/*
gcc `pkg-config --cflags gtk+-3.0` -o phenomenon phenomenon.c `pkg-config --libs gtk+-3.0`
*/

#include <gtk/gtk.h>

void apply_style() {
    GtkCssProvider *provider = gtk_css_provider_new();
    GdkDisplay *display = gdk_display_get_default();
    GdkScreen *screen = gdk_display_get_default_screen(display);

    gtk_style_context_add_provider_for_screen (screen, GTK_STYLE_PROVIDER (provider),
                                            GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
    gtk_css_provider_load_from_path(GTK_CSS_PROVIDER(provider), "phenomenon.css", NULL);
    g_object_unref(provider);
}

void set_window_properties(GtkWidget *window) {
    GtkWindow *gwindow = GTK_WINDOW(window);
    gtk_window_set_title(gwindow, "Phenomenon Text Editor v0.1");
    gtk_window_set_default_size(gwindow, gdk_screen_width()*0.5, gdk_screen_height()*0.5); 
    gtk_window_set_has_resize_grip(gwindow, FALSE);
    g_signal_connect(gwindow, "destroy", G_CALLBACK(gtk_main_quit), NULL);
}

void set_text_view_properties(GtkWidget *text_view, int margin) {
    gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(text_view), GTK_WRAP_WORD_CHAR);
    gtk_text_view_set_pixels_above_lines(GTK_TEXT_VIEW(text_view), 2);

    gtk_text_view_set_left_margin(GTK_TEXT_VIEW(text_view), 5);
    gtk_text_view_set_border_window_size(GTK_TEXT_VIEW(text_view),      
                                         GTK_TEXT_WINDOW_RIGHT,         
                                         margin);
}

void create_layout(GtkWidget *window, GtkWidget *vbox, GtkWidget *menu,
                    GtkWidget *scrolled_window, GtkWidget *text_view, int margin) {

    gtk_container_add(GTK_CONTAINER(window), vbox);
    gtk_container_add(GTK_CONTAINER(vbox), menu);
    gtk_box_pack_end(GTK_BOX(vbox), scrolled_window, 1, 1, 0);
    gtk_container_add(GTK_CONTAINER(scrolled_window), text_view);

    gtk_widget_set_size_request(menu, margin, -1);

    GtkWidget *right_menu = gtk_label_new("");
    gtk_widget_set_name(right_menu, "menu_right");

    gtk_widget_set_size_request(right_menu, margin, gdk_screen_height());

    gtk_text_view_add_child_in_window(GTK_TEXT_VIEW(text_view),         
                                        right_menu,
                                        GTK_TEXT_WINDOW_RIGHT,
                                        0, 0);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled_window),
                                    GTK_POLICY_NEVER, GTK_POLICY_ALWAYS);
}

GtkWidget *create_menu_button(gchar *filename) {
    GtkWidget *box;
    GtkWidget *image;
    GtkWidget *button = gtk_button_new();

    box = gtk_box_new(1, 0);
    image = gtk_image_new_from_file(filename);

    gtk_container_add(GTK_CONTAINER(box), image);
    gtk_container_add(GTK_CONTAINER(button), box);


    return button;
}

gchar *get_icon_path(gchar *filename) {
    return g_strconcat("icons/", filename, ".png", NULL);
}

GtkWidget *create_menu_bar(GtkWidget *menu, int num_args, ...) {

    GtkWidget *menu_bar = gtk_box_new(0, 0);

    va_list buttonlist;
    int i;

    va_start(buttonlist, num_args);
        for(i = 0; i < num_args; i++)
        {
            gchar *filepath = get_icon_path(va_arg(buttonlist, gchar*));
            GtkWidget *button = create_menu_button(filepath);
            gtk_box_pack_start(GTK_BOX(menu_bar), button, 1, 1, 0);
        }
    va_end(buttonlist);

    return menu_bar;
}

void arrange_menu(GtkWidget *menu) {
    GtkWidget *bar1 = create_menu_bar(menu, 4, "new_file", "open_file", "save_file", "saveas_file");
    GtkWidget *bar2 = create_menu_bar(menu, 4, "align_left", "align_center", "align_right", "align_just");
    GtkWidget *bar3 = create_menu_bar(menu, 4, "cut", "copy", "paste", "clipboard");
    GtkWidget *bar4 = create_menu_bar(menu, 4, "bold", "italic", "underline", "stroke");
    GtkWidget *bar5 = create_menu_bar(menu, 4, "undo", "redo", "find", "replace");

    gtk_container_add(GTK_CONTAINER(menu), bar1);
    gtk_container_add(GTK_CONTAINER(menu), bar2);
    gtk_container_add(GTK_CONTAINER(menu), bar3);
    gtk_container_add(GTK_CONTAINER(menu), bar4);
    gtk_container_add(GTK_CONTAINER(menu), bar5);
}

void create_text_widget(GtkWidget *window) {
    int margin = gdk_screen_width()/10;
    GtkWidget *vbox = gtk_box_new(0, 0);
    GtkWidget *menu = gtk_box_new(1, 0);
    GtkWidget *text_view = gtk_text_view_new();
    GtkWidget *scrolled_window = gtk_scrolled_window_new(NULL, NULL);
    
    set_text_view_properties(text_view, margin);
    create_layout(window, vbox, menu, scrolled_window, text_view, margin);

    gtk_widget_set_name(menu, "main_menu_left");
    gtk_widget_set_name(text_view, "main_text_view");

    arrange_menu(menu);
    
    /*
    gtk_text_view_set_justification(GTK_TEXT_VIEW(text_view), 3);
    */
}

int main(int argc, char *argv[]) {
    GtkWidget *window;
    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    set_window_properties(window);
    create_text_widget(window);
    apply_style();

    gtk_widget_show_all(window);
    gtk_window_maximize(GTK_WINDOW(window));
    gtk_main ();

    return 0;
}