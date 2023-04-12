#ifndef GROUPINGWIDGETS_H
#define GROUPINGWIDGETS_H

#include <Wt/WEnvironment.h>
#include <Wt/WApplication.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WGroupBox.h>
#include <Wt/WAnimation.h>
#include <Wt/WIconPair.h>
#include <Wt/WPanel.h>
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
            auto groupBox = root()->addWidget(make_unique<WGroupBox>("A Group Box"));
            groupBox->addNew<WText>("<p>Some Contents</p>");
            groupBox->addNew<WText>("<p>Another Contents</p>");
            groupBox->addNew<WText>("<p>More Contents</p>");
        }
        {
            auto groupBox = root()->addWidget(make_unique<WGroupBox>("A Group Box"));
            groupBox->addNew<WText>("<p>Some Contents</p>");
            groupBox->addNew<WText>("<p>Another Contents</p>");
            groupBox->addNew<WText>("<p>More Contents</p>");
        }
        {
            auto panel = root()->addWidget(make_unique<WPanel>());
            panel->setTitle("Title");
            panel->setCentralWidget(make_unique<WText>("<p>This is a default panel</p>"));
        }
        {
            auto panel = root()->addWidget(make_unique<WPanel>());
            panel->setTitle("Collapsible Panel");
            panel->setCollapsible(true);

            WAnimation animation(
              AnimationEffect::SlideInFromTop,
              TimingFunction::EaseOut,
              100
            );

            panel->setAnimation(animation);
            panel->setCentralWidget(make_unique<WText>("<p>This is a default panel</p>"));
        }

    }


  private:
};

#endif
