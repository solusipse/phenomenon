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
    gtk_text_view_set_right_margin(GTK_TEXT_VIEW(text_view), margin);
}

void create_layout(GtkWidget *window, GtkWidget *vbox, GtkWidget *menu,
                    GtkWidget *scrolled_window, GtkWidget *text_view, int margin) {

    gtk_container_add(GTK_CONTAINER(window), vbox);
    gtk_container_add(GTK_CONTAINER(vbox), menu);
    gtk_box_pack_end(GTK_BOX(vbox), scrolled_window, 1, 1, 0);
    gtk_container_add(GTK_CONTAINER(scrolled_window), text_view);

    gtk_widget_set_size_request(menu, margin, -1);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled_window),
                                    GTK_POLICY_NEVER, GTK_POLICY_ALWAYS);
}

void create_text_widget(GtkWidget *window) {
    int margin = gdk_screen_width()/10;
    GtkWidget *vbox = gtk_box_new(0, 0);
    GtkWidget *menu = gtk_box_new(0, 0);
    GtkWidget *text_view = gtk_text_view_new();
    GtkWidget *scrolled_window = gtk_scrolled_window_new(NULL, NULL);
    
    set_text_view_properties(text_view, margin);
    create_layout(window, vbox, menu, scrolled_window, text_view, margin);

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