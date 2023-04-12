#ifndef CONTAINERWIDGET_H
#define CONTAINERWIDGET_H

#include <Wt/WEnvironment.h>
#include <Wt/WApplication.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WText.h>

using namespace Wt;
using namespace std;

class Application: public WApplication
{
  public:
    Application(const WEnvironment& env)
    : WApplication(env)
    {
        d_containerWidget = root()->addWidget(
            make_unique<WContainerWidget>()
        );
        for(int i = 0; i < 10000; i++)
        d_containerWidget->addNew<WText>("<b class='btn btn-primary' >Hello World</b>");
    }


  private:
    WContainerWidget* d_containerWidget;
};

#endif
