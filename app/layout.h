#ifndef LAYOUT_H
#define LAYOUT_H

#include <Wt/WEnvironment.h>
#include <Wt/WApplication.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WBoxLayout.h>
#include <Wt/WHBoxLayout.h>
#include <Wt/WVBoxLayout.h>
#include <Wt/WGridLayout.h>
#include <Wt/WText.h>

using namespace Wt;
using namespace std;

class Application: public WApplication
{
  public:
    Application(const WEnvironment& env)
    : WApplication(env)
    {
        useStyleSheet("css/style.css");
        addMetaHeader("viewport","width=device-width, initial-scale=10");


        {
            auto container = root()->addWidget(make_unique<WContainerWidget>());
            container->setStyleClass("yellow-box");

            auto hbox = container->setLayout(make_unique<WHBoxLayout>());
            
            auto item = hbox->addWidget(make_unique<WText>("Item 1"));
            item->setStyleClass("green-box");

            item = hbox->addWidget(make_unique<WText>("Item 2"));
            item->setStyleClass("blue-box");
        }
        {
            auto container = root()->addWidget(make_unique<WContainerWidget>());
            container->setStyleClass("yellow-box");

            auto hbox = container->setLayout(make_unique<WHBoxLayout>());
            
            auto item = hbox->addWidget(make_unique<WText>("Item 1"), 1);
            item->setStyleClass("green-box");

            item = hbox->addWidget(make_unique<WText>("Item 2"));
            item->setStyleClass("blue-box");
        }
        {
            auto container = root()->addWidget(make_unique<WContainerWidget>());
            container->setStyleClass("yellow-box");

            auto hbox = container->setLayout(make_unique<WHBoxLayout>());
            
            auto item = hbox->addWidget(make_unique<WText>("Item 1"), 1);
            item->setStyleClass("green-box");

            item = hbox->addWidget(make_unique<WText>("Item 2"), 1);
            item->setStyleClass("blue-box");

            item = hbox->addWidget(make_unique<WText>("Item 3"));
            item->setStyleClass("blue-box");
        }
        {
            auto container = root()->addWidget(make_unique<WContainerWidget>());
            container->setStyleClass("yellow-box");

            auto vbox = container->setLayout(make_unique<WVBoxLayout>());
            
            auto item = vbox->addWidget(make_unique<WText>("Item 1"));
            item->setStyleClass("green-box");

            item = vbox->addWidget(make_unique<WText>("Item 2"));
            item->setStyleClass("blue-box");
        }
        {
            auto container = root()->addWidget(make_unique<WContainerWidget>());
            container->setStyleClass("yellow-box");

            auto vbox = container->setLayout(make_unique<WVBoxLayout>());
            container->setHeight(400);
            
            auto item = vbox->addWidget(make_unique<WText>("Item 1"), 1);
            item->setStyleClass("green-box");

            item = vbox->addWidget(make_unique<WText>("Item 2"));
            item->setStyleClass("blue-box");
        }
        {
            auto container = root()->addWidget(make_unique<WContainerWidget>());
            container->setStyleClass("yellow-box");
            container->setHeight(400);

            auto grid = container->setLayout(make_unique<WGridLayout>());

            for (int row = 0; row < 3; ++row) {
                for(int column = 0; column < 4; ++column) {
                    Wt::WString cell = Wt::WString("Item ({1}, {2})").arg(row).arg(column);
                    auto text = grid->addWidget(
                        make_unique<WText>(cell), row, column
                    );

                    if (row == 1 || column == 1 || column == 2)
                        text->setStyleClass("blue-box");
                    else
                        text->setStyleClass("green-box");
                }
            }

            grid->setRowStretch(1, 1);
            grid->setColumnStretch(1, 1);
            grid->setColumnStretch(2, 1);

        }
        
    }


  private:
};

#endif
