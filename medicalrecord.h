#ifndef MEDICALRECORD_H
#define MEDICALRECORD_H
#include<QString>
#include "patient.h"

class MedicalRecord
{
private:

public:
    Patient *patient;
    QString diagnosis;
    QString treatment;
    QString prescription;
    // MedicalRecord(const QString& patient, const QString& diagnosis, const QString& treatment, const QString& prescription)
    //     : patient(patient), diagnosis(diagnosis), treatment(treatment), prescription(prescription) {}
    MedicalRecord() {}
};

#endif // MEDICALRECORD_H
