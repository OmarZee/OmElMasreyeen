#ifndef MEDICALRECORD_H
#define MEDICALRECORD_H
#include<QString>

class MedicalRecord
{
private:
    QString patient;
    QString diagnosis;
    QString treatment;
    QString prescription;
public:
    MedicalRecord(const QString& patient, const QString& diagnosis, const QString& treatment, const QString& prescription)
        : patient(patient), diagnosis(diagnosis), treatment(treatment), prescription(prescription) {}
};

#endif // MEDICALRECORD_H
