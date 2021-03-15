#include "head.cpp"

int main()
{
    SetConsoleTextAttribute(hcon, 15);
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
        for (;;)
        {
            for (;;)
            {
                selectTrainingHill();
                loadTrainingConfig();
                cout << "Belka startowa: ";
                cin >> hill.startGate;
                hill.startWind = randomDouble(hill.typicalWind[0], hill.typicalWind[1]);
                for (auto jp : jumpersList)
                {
                    cls;
                    jp.afterStart();
                    cout << "Belka: ";
                    cin >> jp.gate;
                    cout << "Wiatr: ";
                    cin >> jp.wind;
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