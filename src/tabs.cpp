#include "tabs.h"

#include "utilities.h"

/* Tabs class */
// its for manipulating tabs from outside

Tabs::Tabs() {

}

void Tabs::close(int i) {
    delete this->fromIndex(i);
    commonUtils.tabsList.remove(i);
    commonUtils.ui->tabPanel->removeTab(i);
}

void Tabs::addToTabsList(Tab *t) {
    commonUtils.tabsList.append(t);
}

int Tabs::currentIndex() {
    return commonUtils.ui->tabPanel->currentIndex();
}

Tab *Tabs::current() {
    return commonUtils.tabsList[currentIndex()];
}

Tab *Tabs::add() {
    return new Tab();
}

Tab *Tabs::fromIndex(int i) {
    return commonUtils.tabsList[i];
}


/* Tab class */
// every tab is of this type

Tab::Tab(QString title, QString text, QString path) {
    this->title = title;
    this->text = text;
    this->path = path;
    Tabs().addToTabsList(this);
    commonUtils.ui->tabPanel->addTab(title);
    commonUtils.ui->tabPanel->setCurrentIndex(this->id());
}

void Tab::close() {
    Tabs().close(this->id());
}

int Tab::id() {
    for(int i = 0; i < commonUtils.tabsList.length(); i++) {
        if (commonUtils.tabsList[i] == this)
            return i;
    }
    return -1;
}

void Tab::update() {
    this->title = commonUtils.getFileName(this->path);
    commonUtils.ui->tabPanel->setTabText(this->id(), this->title);
}
