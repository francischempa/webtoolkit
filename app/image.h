#ifndef IMAGE_H
#define IMAGE_H

#include <Wt/WEnvironment.h>
#include <Wt/WApplication.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WLink.h>
#include <Wt/WImage.h>
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
        {
            auto container = root()->addWidget(make_unique<WContainerWidget>());
            auto image = container->addNew<WImage>(WLink("resources/wt.png"));
            image->setAlternateText("Wt logo");
            auto text = container->addNew<WText>();
            text->setMargin(10, Side::Left);
            image->clicked().connect([=](const WMouseEvent& e){
                text->setText(
                    WString("You clicked the Wt logo at ({1}, {2})")
                        .arg(to_string(e.widget().x))
                        .arg(to_string(e.widget().y))
                );
            });
        }
    }


  private:
    WContainerWidget* d_containerWidget;
};

#endif
