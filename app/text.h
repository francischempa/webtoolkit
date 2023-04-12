#ifndef TEXT_H
#define TEXT_H

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
        root()->addNew<WText>(
            R"(
                <p>This XHTML text contains JavaScript, wich is filtered by the XSS filter.</p>
                <script>
                    alert(\"XSS Attack!\");
                </script>
                <p>A warning is printed in the logs.</p>
            )"
        );

        auto text1 = root()->addNew<WText>("<p>This text reacts to <tt>clicked()</tt></p>");
        text1->setStyleClass("reactive");

        auto text2 = root()->addNew<WText>("<p>This text reacts to <tt>doubleClicked()</tt></p>");
        text2->setStyleClass("reactive");

        auto text3 = root()->addNew<WText>("<p>This text reacts to <tt>mouseWentOver()</tt></p>");
        text3->setStyleClass("reactive");

        auto text4 = root()->addNew<WText>("<p>This text reacts to <tt>mouseWentOut()</tt></p>");
        text4->setStyleClass("reactive");


        auto out = root()->addNew<WText>("<p><tt>Output</tt></p>");


        text1->clicked().connect([=]{
            out->setText("Text 1 was Clicked");
        });
        text2->doubleClicked().connect([=]{
            out->setText("Text 2 was Double Clicked");
        });
        text3->mouseWentOver().connect([=]{
            out->setText("Text 3, Mouse mouse Went Over");
        });
        text4->mouseWentOut().connect([=]{
            out->setText("Text 3, Mouse mouse Went Out");
        });

        auto thisGuy = root()->addNew<WText>("<p>What is this guy's name?</p>");
        thisGuy->setToolTip("His name is Francis Chempa! His is a Genius!");
    }


  private:
};

#endif
