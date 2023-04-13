#ifndef REGISTER_FORM_H
#define REGISTER_FORM_H

#include <Wt/WEnvironment.h>
#include <Wt/WApplication.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WHBoxLayout.h>
#include <Wt/WVBoxLayout.h>
#include <Wt/WLineEdit.h>
#include <Wt/WLineEdit.h>
#include <Wt/WLabel.h>
#include <Wt/WDatePicker.h>
#include <Wt/WTemplate.h>
#include <example.h>

using namespace Wt;
using namespace std;



class Application: public WApplication
{
  public:
    Application(const WEnvironment& env)
    : WApplication(env)
    {
        root()->doJavaScript("document.head.innerHTML += '<meta name=\"viewport\" content=\"width=device-width, initial-scale=1, maximum-scale=1\">';");
        useStyleSheet("css/style.css");
        useStyleSheet("css/bootstrap.min.css");
        require("js/bootstrap.bundle.min.js");
        {
            auto div = root()->addWidget(make_unique<WContainerWidget>());
            div->addNew<WText>("YourEvent");
        }
        {
            auto div = root()->addWidget(make_unique<WContainerWidget>());
            div->addNew<WText>("Online Registration");
        }
        {
            auto div = root()->addWidget(make_unique<WContainerWidget>());
            {
                auto wrapper = div->addWidget(make_unique<WContainerWidget>());
                auto hbox = wrapper->setLayout(make_unique<WHBoxLayout>());
                {
                    auto inputDiv = hbox->addWidget(make_unique<WContainerWidget>());
                    auto vbox = inputDiv->setLayout(make_unique<WVBoxLayout>());
                    vbox->addWidget(make_unique<WLabel>("First Name"));
                    auto lineEdit = vbox->addWidget(make_unique<WLineEdit>());

                }
                {
                    auto inputDiv = hbox->addWidget(make_unique<WContainerWidget>());
                    auto vbox = inputDiv->setLayout(make_unique<WVBoxLayout>());
                    vbox->addWidget(make_unique<WLabel>("Last Name"));
                    auto lineEdit = vbox->addWidget(make_unique<WLineEdit>());
                }
                wrapper->addStyleClass("form-control");
            }
            {
                auto wrapper = div->addWidget(make_unique<WContainerWidget>());
                auto vbox = wrapper->setLayout(make_unique<WVBoxLayout>());
                vbox->addWidget(make_unique<WLabel>("Email Address"));
                auto lineEdit = vbox->addWidget(make_unique<WLineEdit>());
            }
            {
                auto wrapper = div->addWidget(make_unique<WContainerWidget>());
                auto vbox = wrapper->setLayout(make_unique<WVBoxLayout>());
                vbox->addWidget(make_unique<WLabel>("Company (if applicable)"));
                auto lineEdit = vbox->addWidget(make_unique<WLineEdit>());
            }
            {
                auto wrapper = div->addWidget(make_unique<WContainerWidget>());
                auto vbox = wrapper->setLayout(make_unique<WVBoxLayout>());
                vbox->addWidget(make_unique<WLabel>("Pysical Address"));
                auto lineEdit = vbox->addWidget(make_unique<WLineEdit>());
            }
            {
                auto wrapper = div->addWidget(make_unique<WContainerWidget>());
                auto tp = wrapper->addWidget(make_unique<WTemplate>());
                tp->setTemplateText(html::example);
                
            }
            

        }
    }


  private:
};

#endif
