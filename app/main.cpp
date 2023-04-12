#include <Wt/WApplication.h>
#include <Wt/WBreak.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WLineEdit.h>
#include <Wt/WPushButton.h>
#include <Wt/WText.h>

// #include "containerwidget.h"
// #include "templates.h"
// #include "text.h"
// #include "groupingwidgets.h"
// #include "layout.h"
// #include "dialogs.h"
// #include "image.h"
#include "registerform.h"

using namespace std;
using namespace Wt;

int main(int argc, char **argv)
{
    return WRun(argc, argv, [&](const WEnvironment &env)
    {
        return make_unique<Application>(env);
    });
}