#include "head.h"
void Save::initSave(string filename)
{
    cout << "";
}

void Jumper::afterStart()
{
    cout << name << " " << surname << " (" << nationality << ")" << endl;
    getch();
}

void Jumper::jump()
{
    hill.startup();
    hill.setType();
    wind += randomDouble(hill.windChange[0], hill.windChange[1]);
    windB = wind + normalRandom(0, hill.windFaulty);

    int rd;
    if (takeoffPowerS > 120)
        takeoffPowerS = 120;
    if (takeoffPowerS < 1)
        takeoffPowerS = 1;
    if (takeoffTechniqueS > 120)
        takeoffTechniqueS = 120;
    if (takeoffTechniqueS < 1)
        takeoffTechniqueS = 1;
    if (flightTechniqueS > 120)
        flightTechniqueS = 120;
    if (flightTechniqueS < 1)
        flightTechniqueS = 1;
    if (flightStyle > 4)
        flightStyle = 2; //Styl "nowoczesne V 1"
    if (skisPositionS > 14)
        skisPositionS = 10;
    takeoffPower = (takeoffPowerS);
    takeoffPower += normalRandom(0, 5);
    takeoffPower = round(takeoffPower);
    if (takeoffPower > 160)
        takeoffPower = 160;
    else if (takeoffPower < 1)
        takeoffPower = 1;

    takeoffTechnique = (takeoffTechniqueS * 0.987) + (form * 1.05);
    takeoffTechnique += normalRandom(0, 7);
    takeoffTechnique = round(takeoffTechnique);
    if (takeoffTechnique > 280)
        takeoffTechnique = 280;
    if (takeoffTechnique < 1)
        takeoffTechnique = 1;

    int test1 = 20 - hill.flightStyleMeters[flightStyle] + randomInt(-4, 0);
    flightTechnique = (flightTechniqueS * 0.887) + (form * 1.15);
    if (flightStyle == 0)
        flightTechnique += randomInt(-11, -5);
    else if (flightStyle == 1)
        flightTechnique += randomInt(-2, 2);
    else if (flightStyle == 2)
        flightTechnique += randomInt(-3, 3);
    else if (flightStyle == 3)
        flightTechnique += randomInt(-4, 4);
    else if (flightStyle == 4)
        flightTechnique += randomInt(-5, 5);

    flightTechnique += normalRandom(0, 7);
    flightTechnique = round(flightTechnique);
    if (flightTechnique > 280)
        flightTechnique = 280;
    if (flightTechnique < 1)
        flightTechnique = 1;

    if (hill.gateMeters == (-1))
    {
        hill.gateMeters = (hill.gatePoints / hill.metersPoints);
    }
    if (hill.windMetersBack == (-1))
    {
        hill.windMetersBack = (hill.windMetersBack / hill.metersPoints);
    }
    if (hill.windMetersFront == (-1))
    {
        hill.windMetersFront = (hill.windMetersFront / hill.metersPoints);
    }

    if (windB < 0)
        compensationWind = -windB * hill.windPointsBack;
    else if (windB > 0)
        compensationWind = -windB * hill.windPointsFront;

    compensationGate = (hill.startGate - gate) * hill.gatePoints;

    double diff;
    diff = (takeoffPower - hill.optimalTakeoffPower);

    if (diff < 0)
        (diff *= 0.6456);
    else
        diff *= 0.44;

    //odlegˆo˜†
    distance = hill.startDist;
    //cout << "Odl: " << distance << endl;
    distance += (gate * hill.gateMeters);
    //cout << "Odl: " << distance << endl;

    if (windB > 0)
        distance += (windB * hill.windMetersFront);
    else if (windB < 0)
        distance += (windB * hill.windMetersBack);
    //cout << "Odl: " << distance << endl;

    //wiatr
    //for (auto sn : windSensor)
    //  sn += randomDouble(-hill.windFaulty, hill.windFaulty);

    distance += (diff * hill.takeoffPowerImportance);
    //cout << "Odl: " << distance << endl;
    distance += takeoffTechnique * hill.takeoffTechniqueMeters;
    //cout << "Odl: " << distance << endl;
    distance += flightTechnique * hill.flightTechniqueMeters;
    //cout << "Odl: " << distance << endl;
    for (int i = 0; i < 5; i++)
    {
        if (flightStyle == i)
        {
            distance += hill.flightStyleMeters[i];
        }
    }
    //cout << "Odl: " << distance << endl;
    distance = round(distance * 2) / 2;
    //cout << "Odl: " << distance << endl;

    if (points < 0)
        points = 0;
    points = (hill.pointsForK + (hill.metersPoints * (distance - hill.kpoint) + judgesAll + (compensationGate + compensationWind)));
}

void Jumper::showResult()
{
    cout << name << " " << surname << " (" << nationality << ")" << endl;
    cout << "Odlegˆo˜†: " << distance << "m" << endl;
    if (windB < 0)
    {
        colorText(12, "Wiatr: ");
        colorText(12, to_string(windB));
    }

    else if (windB > 0)
    {
        colorText(10, "Wiatr: ");
        colorText(10, to_string(windB));
    }
    else
    {
        colorText(7, "Wiatr: ");
        colorText(7, to_string(windB));
    }
    cout << endl;
    if (compensationGate < 0)
    {
        colorText(12, "Za belke: ");
        colorText(12, to_string(compensationGate));
    }
    else if (compensationGate > 0)
    {
        colorText(10, "Za belke: ");
        colorText(10, to_string(compensationGate));
    }
    else
    {
        colorText(7, "Za belke: ");
        colorText(7, to_string(compensationGate));
    }
    cout << endl;
    if (compensationWind < 0)
    {
        colorText(12, "Za wiatr: ");
        colorText(12, to_string(compensationWind));
    }
    else if (compensationWind > 0)
    {
        colorText(10, "Za wiatr: ");
        colorText(10, to_string(compensationWind));
    }
    else
    {
        colorText(7, "Za wiatr: ");
        colorText(7, to_string(compensationWind));
    }
    cout << endl;
    if ((compensationWind + compensationGate) < 0)
    {
        colorText(12, "Lacznie: ");
        colorText(12, to_string((compensationWind + compensationGate)));
    }
    else if ((compensationWind + compensationGate) > 0)
    {
        colorText(10, "Lacznie: ");
        colorText(10, to_string((compensationWind + compensationGate)));
    }
    else
    {
        colorText(7, "Lacznie: ");
        colorText(7, to_string((compensationWind + compensationGate)));
    }

    SetConsoleTextAttribute(hcon, 15);
    cout << "\nPunkty: " << points << endl;
}

void Jumper::showHideInfo()
{
    cout << "Moc wybicia: " << takeoffPower << ", Technika wybicia: " << takeoffTechnique << ", Technika lotu: " << flightTechnique << endl;
}

void Jumper::showDistanceAndToBeat()
{
    for (int i = 0; i <= distance; i++)
    {
        if (i == distance)
        {
            cout << "| " << i << "m |" << endl;
        }
        else
            cout << i << "m" << endl;

        if (distance - i < 5 + (randomInt(-12, 12)))
            Sleep(86);
        else if (distance - i < 10 + (randomInt(-12, 12)))
            Sleep(76);
        else if (distance - i < 25 + (randomInt(-12, 12)))
            Sleep(64);
        else if (distance - i < 45 + (randomInt(-12, 12)))
            Sleep(51);
        else if (distance - i < 70 + (randomInt(-12, 12)))
            Sleep(34);
        else if (distance - i < 100 + (randomInt(-12, 12)))
            Sleep(20);
        else if (distance - i < 150 + (randomInt(-12, 12)))
            Sleep(15);
        else
            Sleep(10);

        cls;
    }
    cls;
}

void Hill::startup()
{
    pointsForK = 60;
    if (kpoint <= 25)
        metersPoints = 4.8;
    else if (hill.kpoint <= 30)
        metersPoints = 4.4;
    else if (hill.kpoint <= 34)
        metersPoints = 4;
    else if (hill.kpoint <= 39)
        metersPoints = 3.6;
    else if (hill.kpoint <= 49)
        metersPoints = 3.2;
    else if (hill.kpoint <= 59)
        metersPoints = 2.8;
    else if (hill.kpoint <= 69)
        metersPoints = 2.4;
    else if (hill.kpoint <= 79)
        metersPoints = 2.2;
    else if (hill.kpoint <= 99)
        metersPoints = 2.0;
    else if (hill.kpoint <= 169)
        metersPoints = 1.8;
    else if (hill.kpoint >= 170)
    {
        metersPoints = 1.2;
        hill.pointsForK = 120;
    }
}

void Hill::setType()
{
    if (kpoint <= 0)
        type = "brak danych";
    if (kpoint <= 44)
        type = "maˆa";
    if (kpoint <= 74)
        type = "˜rednia";
    if (kpoint <= 99)
        type = "normalna";
    if (kpoint <= 169)
        type = "du¾a";
    else
        type = "mamucia";
}
int randomInt(int a, int b)
{
    /*int r1, r2[3000], r3;
    random_device dev;
    uniform_int_distribution<int> rd(a, b);
    uniform_int_distribution<int> rd1(0, 2999);
    r1 = rd1(dev);
    for (auto rr : r2)
    {
        rr = rd(dev);
    }
    r3 = r2[r1];
    return r3;*/
    random_device dev;
    uniform_int_distribution<int> rd(a, b);
    return rd(dev);
}

double randomDouble(double min, double max)
{
    srand(time(NULL));
    double rr[50];
    int rrr = randomInt(0, 49);
    for (int i = 0; i <= 49; i++)
    {
        rr[i] = ((double)rand() / RAND_MAX) * (max - min) + min;
    }
    return rr[rrr];
}

void colorText(unsigned short color, string text)
{
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hcon, color);
    cout << text;
}

double percent(double prc, double num)
{
    double sum;
    sum = (prc / 100) * num;
    return sum;
}

double normalRandom(double mid, double a)
{
    srand(time(NULL));
    default_random_engine gen;
    normal_distribution<double> ndist(mid, a);
    double result, min, max;
    double rd[1000];
    int nr = randomInt(0, 999);

    for (int i = 0; i < 1000; i++)
    {
        rd[i] = ndist(gen);
        if (i == 0)
        {
            min = rd[i];
            max = rd[i];
        }
        if (rd[i] > max)
            max = rd[i];
        else if (rd[i] < min)
            min = rd[i];
    }

    return rd[nr];
}
void binomalRandom(int up, int chance)
{
    default_random_engine gen;
    binomial_distribution<int> bdist(up, chance);

    for (int i = 0; i <= 100; i++)
    {
        cout << i + 1 << ". " << bdist(gen) << endl;
    }
}

void selectTrainingHill()
{
    int i = 1, c;
    for (auto hill : hills)
    {
        cout << i << ". " << hill.name << " (" << hill.country << ") " << hill.kpoint << " " << hill.hspoint << endl;
        i++;
    }
    cout << "Skocznia: ";
    cin >> c;
    hill = hills[c - 1];
}

void loadHills()
{
    Hill vechill;
    string tmp;
    hlf.open("../resources/hills.csv", ios::in);
    if (hlf.good() == false)
    {
        cout << "Nie udalo sie otworzyc pliku. Zamykam program...";
        Sleep(2500);
        exit(0);
    }
    while (getline(hlf, vechill.name, ','))
    {
        getline(hlf, vechill.country, ',');
        getline(hlf, tmp, ',');
        vechill.kpoint = stoi(tmp);
        getline(hlf, tmp, ',');
        vechill.hspoint = stoi(tmp);
        getline(hlf, tmp, ',');
        vechill.gatePoints = stod(tmp);
        getline(hlf, tmp, ',');
        vechill.gateMeters = stod(tmp);
        getline(hlf, tmp, ',');
        vechill.windPointsFront = stod(tmp);
        getline(hlf, tmp, ',');
        vechill.windMetersFront = stod(tmp);
        getline(hlf, tmp, ',');
        vechill.windPointsBack = stod(tmp);
        getline(hlf, tmp, ',');
        vechill.windMetersBack = stod(tmp);
        getline(hlf, tmp, ',');
        vechill.maxdist = stod(tmp);
        getline(hlf, tmp, ',');
        vechill.startDist = stod(tmp);
        getline(hlf, tmp, ',');
        vechill.hsLandDifficulty = stod(tmp);
        getline(hlf, tmp, ',');
        vechill.flightStyleMeters[0] = stod(tmp);
        getline(hlf, tmp, ',');
        vechill.flightStyleMeters[1] = stod(tmp);
        getline(hlf, tmp, ',');
        vechill.flightStyleMeters[2] = stod(tmp);
        getline(hlf, tmp, ',');
        vechill.flightStyleMeters[3] = stod(tmp);
        getline(hlf, tmp, ',');
        vechill.flightStyleMeters[4] = stod(tmp);
        getline(hlf, tmp, ',');
        vechill.optimalTakeoffPower = stoi(tmp);
        getline(hlf, tmp, ',');
        vechill.takeoffPowerImportance = stod(tmp);
        getline(hlf, tmp, ',');
        vechill.takeoffTechniqueMeters = stod(tmp);
        getline(hlf, tmp);
        vechill.flightTechniqueMeters = stod(tmp);
        hills.push_back(vechill);
    }
    hlf.close();
}

void loadJumpers(bool ifForm)
{
    Jumper jp;
    string tmp;
    jpf.open("../resources/jumpers.csv", ios::in);
    while (getline(jpf, jp.name, ','))
    {
        getline(jpf, jp.surname, ',');
        getline(jpf, jp.nationality, ',');
        getline(jpf, tmp, ',');
        jp.height = stoi(tmp);
        getline(jpf, tmp, ',');
        jp.age = stoi(tmp);
        getline(jpf, tmp, ',');
        jp.takeoffPowerS = stoi(tmp);
        getline(jpf, tmp, ',');
        jp.takeoffTechniqueS = stoi(tmp);
        getline(jpf, tmp, ',');
        jp.flightTechniqueS = stoi(tmp);
        getline(jpf, tmp, ',');
        jp.flightStyle = stoi(tmp);
        getline(jpf, tmp, ',');
        jp.landSkillS = stoi(tmp);
        getline(jpf, tmp, ',');
        jp.landStyleS = stoi(tmp);
        getline(jpf, tmp, ',');
        jp.expernice = stoi(tmp);
        if (ifForm == true)
        {
            getline(jpf, tmp, ',');
            jp.form = stoi(tmp);
        }
        getline(jpf, tmp);
        jp.injuryResistance = stoi(tmp);
        jumpersList.push_back(jp);
    }
    jpf.close();
}

void loadTrainingConfig()
{
    string tmp;
    ;
    tcf.open("../resources/trainingconfig.csv", ios::in);
    getline(tcf, tmp, ',');
    hill.windFaulty = stod(tmp);
    //cout << tmp;
    getline(tcf, tmp, ',');
    hill.typicalWind[0] = stod(tmp);
    //cout << tmp;
    getline(tcf, tmp, ',');
    hill.typicalWind[1] = stod(tmp);
    //cout << tmp;
    getline(tcf, tmp, ',');
    hill.windChange[0] = stod(tmp);
    //cout << tmp;
    getline(tcf, tmp);
    hill.windChange[1] = stod(tmp);
    //cout << tmp;
    tcf.close();
}

void selectTrainingJumper()
{
    int i = 1;
    int c;
    for (auto jp : jumpersList)
    {
        cout << i << ". " << jp.name << " " << jp.surname << " (" << jp.nationality << ") (" << jp.age << " lat ) "
             << "(Forma: " << jp.form << ")" << endl;
        i++;
    }
    Sleep(300);
    cout << "Skoczek: ";
    cin >> c;
    trainingJumper = jumpersList[c - 1];
}

void showHillInfo(Hill hl)
{
    cout << hl.name << " (" << hl.country << ") K" << hl.kpoint << " HS" << hl.hspoint << " (" << percent(95, hl.hspoint) << ") " << endl;
    cout << "Punkty za belke: " << hl.gatePoints << endl;
    cout << "Punkty za wiatr przedni: " << hl.windPointsFront << endl;
    cout << "Punkty za wiatr tylni: " << hl.windPointsBack << endl;
}