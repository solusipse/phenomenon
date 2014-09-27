#include "tabs.h"

#include "utilities.h"

/* Tabs class */
// its for manipulating tabs from outside

Tabs::Tabs() {

}

void Tabs::close(int i) {
    commonUtils.ui->tabPanel->removeTab(i);
}

void Tabs::addToTabsList(Tab *t) {
    commonUtils.tabsList.append(t);
}


/* Tab class */
// every tab is of this type

Tab::Tab(QString title) {
    Tabs().addToTabsList(this);
    commonUtils.ui->tabPanel->addTab(title);
}

void Tab::close() {
    // TODO: get its own index
    commonUtils.ui->tabPanel->removeTab(0);
}
