#pragma once
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <cstdio>
#include <cstdlib>
#include <time.h>
#include <iomanip>
#include <conio.h>
#include <fstream>
#include <algorithm>
#include <string>
#include <random>
#include <vector>
#include <ctime>
#include <map>
#include <stdlib.h>
#include <list>
#include <locale.h>
using namespace std;
HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);

#define APP_VERSION "0.0.1"
#define DEFAULT_SAVEFILENAME "save.sav"
#define cls system("cls")
#define hillsfile hlf
#define jumpersfile jpf
#define trainingconfigfile tcf
#define nationsfile ntf

class Jumper
{
public:
    //atrybuty
    string name, surname;
    int height, age;
    string nationality;
    int takeoffPowerS, takeoffTechniqueS;
    int skisPositionS, flightStyle;
    int takeoffPower, takeoffTechnique;
    int skisPosition, transitionSpeed;
    int flightTechnique, flightTechniqueS;
    int landSkillS, landStyleS;
    int expernice, condition, readyToJump, form, happiness, injuryResistance;
    int gate;
    double distance, toBeat;
    double judges[5], minJudge, maxJudge, wind, windB, windBonus, judgeRating, judgesPoints, judgesAll;
    double points, compensationGate, compensationWind;
    bool dsq;
    double windSensor[10];
    void afterStart();
    void jump();
    void showResult();
    void showHideInfo();
    void showDistanceAndToBeat();
};

class Hill
{
public:
    string name, country, type;
    double gatePoints, gateMeters;
    int kpoint, hspoint, pointsForK;
    double maxdist;
    double windMetersFront, windMetersBack, windPointsFront, windPointsBack;
    double metersPoints, hsLandDifficulty;
    double startDist, takeoffDist, flightDist, minWindChange, maxWindChange;
    int optimalSkisPosition;
    double skisPositionEffect;
    double takeoffTechniqueMeters, flightTechniqueMeters;
    int optimalTakeoffPower;
    double flightStyleMeters[5];
    double takeoffPowerImportance;
    int startGate;
    double typicalWind[2], windChange[2], startWind;

    //config

    double windFaulty;
    void startup();
    void setType();
};
class Time
{
public:
    int year, month, day;
    void skip(int nmb);
};
class Save
{
public:
    string filename;
    fstream sfile;
    void initSave(string filename);
    void save(string filename);
    void load(string filename);
};
Hill hill;
Jumper trainingJumper;
Save save;
fstream hillsfile, jumpersfile, trainingconfigfile, nationsfile;
int randomInt(int, int);
double randomDouble(double, double);
void colorText(unsigned short color, string text);
double percent(double prc, double num);
double normalRandom(double mid, double a);
void binomalRandom(int up, int chance);
//-----------------------------//
void loadHills();
void loadJumpers(bool ifForm);
void loadTrainingConfig();
void selectTrainingHill();
void selectTrainingJumper();
void showHillInfo(Hill hl);

vector<Hill> hills;
vector<Jumper> jumpersList;