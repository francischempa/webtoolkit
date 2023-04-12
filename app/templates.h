#ifndef TEMPLATES_H
#define TEMPLATES_H

#include <Wt/WEnvironment.h>
#include <Wt/WApplication.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WTemplate.h>
#include <Wt/WText.h>

using namespace Wt;
using namespace std;

class Application: public WApplication
{
  public:
    Application(const WEnvironment& env)
    : WApplication(env)
    {
        d_template = root()->addWidget(
            make_unique<WTemplate>(WString::tr("app/res/template.html"))
        );

        d_template->setTemplateText(
            R"(
            <div class="form">
                <p>
                    <label>Please enter your name: ${name-edit}</label>
                </p>
                <p>
                    ${save-button} ${cancel-button}
                </p>
            </div>
            )"
        );


        d_template->bindWidget("name-edit", std::make_unique<Wt::WLineEdit>());
        d_template->bindWidget("save-button", std::make_unique<Wt::WPushButton>("Save"));
        d_template->bindWidget("cancel-button", std::make_unique<Wt::WPushButton>("Cancel"));
    }


  private:
    WTemplate* d_template;
};

#endif
