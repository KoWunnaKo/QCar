#include "obdpid.h"

const QString OBDPID::DEFAULT_PID         = "0100";
const QString OBDPID::DEFAULT_NAME        = "No name";
const QString OBDPID::DEFAULT_DESCRIPTION = "No description";
const int OBDPID::DEFAULT_POLL_INTERVAL   = 100;
const QString OBDPID::DEFAULT_FORMULA     = "";
const int OBDPID::DEFAULT_NB_LINES        = 0;

OBDPID::OBDPID()
{
    setPid(DEFAULT_PID);
    setName(DEFAULT_NAME);
    setDescription(DEFAULT_DESCRIPTION);
    setPollInterval(DEFAULT_POLL_INTERVAL);
    setFormula(DEFAULT_FORMULA);
    setNbLines(DEFAULT_NB_LINES);
    pollTime = new QTime();
    pollTime->start();
}

OBDPID::OBDPID(QString pid, QString name, QString description, QString unit, int pollInterval, QString formula, int nbLines)
{
    setPid(pid);
    setName(name);
    setDescription(description);
    setUnit(unit);
    setPollInterval(pollInterval);
    setFormula(formula);
    setNbLines(nbLines);    
    pollTime = new QTime();
    pollTime->start();
}

OBDPID::~OBDPID()
{
    delete pollTime;
}

double OBDPID::computeValue(QStringList data)
{
    QString line1 = data.first();
    line1.replace(QString(" "), QString(""));
    if(line1.at(0) == '4' && line1.at(1) == '1')
    {
        line1 = line1.right(line1.length()-2);
    }
    return -1.0;
}

void OBDPID::createFormulaInterpreter()
{
}

QString OBDPID::getPid() const
{
    return pid;
}

void OBDPID::setPid(const QString &value)
{
    pid = value;
}

QString OBDPID::getDescription() const
{
    return description;
}

void OBDPID::setDescription(const QString &value)
{
    description = value;
}

QTime *OBDPID::getPollTime() const
{
    return pollTime;
}

void OBDPID::setPollTime(QTime *value)
{
    pollTime = value;
}

int OBDPID::getPollInterval() const
{
    return pollInterval;
}

void OBDPID::setPollInterval(int value)
{
    pollInterval = value;
}

QString OBDPID::getFormula() const
{
    return formula;
}

void OBDPID::setFormula(const QString &value)
{
    formula = value;
}

QString OBDPID::getUnit() const
{
    return unit;
}

void OBDPID::setUnit(const QString &value)
{
    unit = value;
}

int OBDPID::getNbLines() const
{
    return nbLines;
}

void OBDPID::setNbLines(int value)
{
    nbLines = value;
}

QString OBDPID::getName() const
{
    return name;
}

void OBDPID::setName(const QString &value)
{
    name = value;
}