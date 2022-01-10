#include <iostream>
#include "GameCommand.h"
#include "GameObject.h"
#include "Building.h"
#include "Student.h"
#include "GradStudent.h"
#include "DoctorsOffice.h"
#include "ClassRoom.h"
#include "View.h"
#include "Input_Handling.h"
#include "Model.h"
#include <typeinfo>
using namespace std;

int main()
{
    cout << "Welcome to COVID Game!" << endl;

    Model* main_model = new Model();
    View* main_view = new View();

    main_model -> Display(*main_view);
    main_model -> ShowStatus();

    while (true)
    {
        int student_id;
        int grad_id;
        int office_id;
        int class_id;
        int vaccine_amount;
        int assignment_amount;
        int x;
        int y;
        char game_command ;
        cout << "Enter game command: ";
        cin >> game_command;
        try
        {
        if (game_command != 'm' && game_command != 'd' && game_command != 'c' && game_command != 's' && game_command != 'v' && game_command != 'a' && game_command != 'g' && game_command != 'r' && game_command != 'q' && game_command != 'n' && game_command != 'w')
        {
            throw Invalid_Input("Valid commands are m, n, d, c, s, v, a, g, r, q, w");
        }
        switch (game_command)
        {
            case 'm':
            {
            cout << "Enter student id, x, y" << endl;
            if (!(cin >> student_id >> x >> y))
            {
                throw Invalid_Input("Was expecting three integers");
            }
            Point2D loc(x,y);
            DoMoveCommand(*main_model, student_id, loc);
            main_model -> Display(*main_view);
            break;
            }

            case 'w':
            {
            cout << "Enter grad id, x, y" << endl;
            if (!(cin >> grad_id >> x >> y))
            {
                throw Invalid_Input("Was expecting three integers");
            }
            Point2D loc(x,y);
            DoGradMoveCommand(*main_model, grad_id, loc);
            main_model -> Display(*main_view);
            break;
            }

            {
            case 'd':
            cout << "Enter student id, office id" << endl;
            if (!(cin >> student_id >> office_id))
            {
                throw Invalid_Input("Was expecting two integers");
            }
            DoMoveToDoctorCommand(*main_model, student_id, office_id);
            main_model -> Display(*main_view);
            break;
            }
            {
            case 'c':
            cout << "Enter student id, class id" << endl;
            if (!(cin >> student_id >> class_id))
            {
                throw Invalid_Input("Was expecting two integers");
            }
            DoMoveToClassCommand(*main_model, student_id, class_id);
            main_model -> Display(*main_view);
            break;
            }

            {
            case 's':
            cout << "Enter student id" << endl;
            if (!(cin >> student_id))
            {
                throw Invalid_Input("Was expecting an integer");
            }
            DoStopCommand(*main_model, student_id);
            main_model -> Display(*main_view);
            break;
            }

            {
            case 'v':
            cout << "Enter student id, vaccine amount" << endl;
            if (!(cin >> student_id >> vaccine_amount))
            {
                throw Invalid_Input("Was expecting two integers");
            }
            DoRecoverInOfficeCommand(*main_model, student_id, vaccine_amount);
            main_model -> Display(*main_view);
            break;
            }

            {
            case 'a':
            cout << "Enter student id, assignment amount" << endl;
            if (!(cin >> student_id >> assignment_amount))
            {
                throw Invalid_Input("Was expecting two integers");
            }
            DoLearningCommand(*main_model, student_id, assignment_amount);
            main_model -> Display(*main_view);
            break;
            }

            {
            case 'g':
            DoGoCommand(*main_model, *main_view);
            main_model -> ShowStatus();
            break;
            }


            {
            case 'r':
            DoRunCommand(*main_model, *main_view);
            main_model -> ShowStatus();
            break;
            }

            {
            case 'q':
            exit(0);
            }

            case 'n':
            main_model -> NewCommand();
        }
        }
        catch (Invalid_Input& except)
        {
        cout << "Invalid input - " << except.msg_ptr << endl;
        cin.clear();
        cin.ignore(50, '\n');
        }
    }
    return 0;
}