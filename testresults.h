#ifndef TESTRESULTS_H
#define TESTRESULTS_H
#include <QString>
#include "patient.h"

class TestResults
{
public:
    TestResults();
    Patient *patient;
    QString diabetes;
    QString bloodType;
    QString RBC;
    QString WBC;
    QString CBC;
};

extern std::vector<TestResults> testResults;

#endif // TESTRESULTS_H
