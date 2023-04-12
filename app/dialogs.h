#ifndef DIALOG_H
#define DIALOG_H

#include <Wt/WEnvironment.h>
#include <Wt/WApplication.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WDialog.h>
#include <Wt/WLineEdit.h>
#include <Wt/WPushButton.h>
#include <Wt/WRegExpValidator.h>
#include <Wt/WBreak.h>
#include <Wt/WLabel.h>
#include <Wt/WMessageBox.h>
#include <Wt/WText.h>

#include <Wt/WBootstrap5Theme.h>

using namespace Wt;
using namespace std;

class Application: public WApplication
{
  public:
    Application(const WEnvironment& env)
    : WApplication(env)
    {
        useStyleSheet("css/style.css");
        setTheme(make_shared<WBootstrap5Theme>());

        {
            auto container = root()->addWidget(make_unique<WContainerWidget>());
            auto button = container->addNew<WPushButton>("Jump // Dialog");

            auto out = container->addNew<WText>();

            button->clicked().connect([=]{
                showDialog(container, out);
            });
        }
        {
            auto container = root()->addWidget(make_unique<WContainerWidget>());
            auto button = container->addNew<WPushButton>("Status // Dialog");

            auto out = container->addNew<WText>();

            button->clicked().connect([=]{
                out->setText("The status button is clicked!");
                auto messageBox = container->addChild(make_unique<WMessageBox>(
                    "Status",
                    R"(
                        <p>Reader to launch the rocket...</p>
                        <p>Launch the rocket immediately?</p>
                    )",
                    Icon::Information,
                    StandardButton::Yes | StandardButton::No
                ));
                messageBox->setModal(true);

                messageBox->buttonClicked().connect([=]{
                    if(messageBox->buttonResult() == StandardButton::Yes)
                        out->setText("The rocket is launched");
                    else
                        out->setText("The rocket is ready for launch");

                    container->removeChild(messageBox);
                });
                messageBox->show();
            });
        }



    }

    void showDialog(WObject* parent, WText* out)
    {
        auto dialog = parent->addChild(make_unique<WDialog>("Go to Cell"));
        auto label = dialog->contents()->addNew<WLabel>("Cell Location (A1 ... Z99)");
        auto edit = dialog->contents()->addNew<WLineEdit>();
        label->setBuddy(edit);
        dialog->contents()->addStyleClass("form-group");
        dialog->setWidth(400);

        auto validator = make_shared<WRegExpValidator>("[A-Za-z][1-9][0-9]{0,2}");
        validator->setMandatory(true);
        edit->setValidator(validator);

        auto ok = dialog->footer()->addNew<WPushButton>("OK");
        ok->setDefault(true);
        ok->addStyleClass("btn btn-success");
        ok->setWidth(100);

        if(environment().ajax())
        {
            ok->disable();
        }

        auto cancel = dialog->footer()->addNew<WPushButton>("Cancel");
        dialog->rejectWhenEscapePressed();

        edit->keyWentUp().connect([=]{
            ok->setDisabled(edit->validate() != ValidationState::Valid);
        });

        ok->clicked().connect([=]{
            if(edit->validate() == ValidationState::Valid)
                dialog->accept();
        });

        cancel->clicked().connect([=]{
            dialog->reject();
        });
        cancel->setWidth(100);
        cancel->addStyleClass("btn btn-danger");

        dialog->finished().connect([=]{
            if(dialog->result() == DialogCode::Accepted)
                out->setText("New location: " + edit->text());
            else
                out->setText("No location selected");
            parent->removeChild(dialog);
        });

        dialog->show();
    }

  private:
};

#endif
