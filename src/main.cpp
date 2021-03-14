#include "head.cpp"

int main()
{
    Jumper testjumper;
    loadHills();
    loadJumpers(true);

    //cout << "Skoczek (MW, TW, F, TL): ";
    //cin >> testjumper.takeoffPowerS >> testjumper.takeoffTechniqueS >> testjumper.form >> testjumper.flightTechniqueS;
    char choice;
    string choice1;
    cout << "Ski Jumper Perspective " << APP_VERSION;
    cout << "\nOpcje: \n1. Nowy zapis gry\n2. Wczytaj istniej¥cy zapis gry\n3. Wy˜wietl wczytane zasoby\n4. Pojedyäczy skok\n";
    choice = getch();
    cls;
    switch (choice)
    {
    case '1':
    {
        cout << "Podaj nazw© pliku (bez rozszerzenia): ";
        save.initSave(choice1 + ".sav");
    }
    case '4':
    {
        cls;
        //selectTrainingHill();
        //cls;
        //showHillInfo(hill);
        //getch();
        //cls;
        // selectTrainingJumper();
        for (;;)
        {
            for (;;)
            {
                selectTrainingHill();
                cout << "Belka startowa: ";
                cin >> hill.startGate;
                for (auto jp : jumpersList)
                {
                    jp.wind = 0;
                    cls;
                    jp.afterStart();
                    jp.jump();
                    jp.showDistanceAndToBeat();
                    jp.showResult();
                    getch();
                    cls;
                }
            }
            getch();
        }
    }
    }

    getch();
}