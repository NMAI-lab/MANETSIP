//
// Generated file, do not edit! Created by nedtool 4.6 from testapp/P2PSIPTestAppMessages.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "P2PSIPTestAppMessages_m.h"

USING_NAMESPACE


// Another default rule (prevents compiler from choosing base class' doPacking())
template<typename T>
void doPacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doPacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}

template<typename T>
void doUnpacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doUnpacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}




// Template rule for outputting std::vector<T> types
template<typename T, typename A>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec)
{
    out.put('{');
    for(typename std::vector<T,A>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (it != vec.begin()) {
            out.put(','); out.put(' ');
        }
        out << *it;
    }
    out.put('}');
    
    char buf[32];
    sprintf(buf, " (size=%u)", (unsigned int)vec.size());
    out.write(buf, strlen(buf));
    return out;
}

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const T&) {return out;}

Register_Class(SIPChallengeCall);

SIPChallengeCall::SIPChallengeCall(const char *name, int kind) : ::BaseCallMessage(name,kind)
{
}

SIPChallengeCall::SIPChallengeCall(const SIPChallengeCall& other) : ::BaseCallMessage(other)
{
    copy(other);
}

SIPChallengeCall::~SIPChallengeCall()
{
}

SIPChallengeCall& SIPChallengeCall::operator=(const SIPChallengeCall& other)
{
    if (this==&other) return *this;
    ::BaseCallMessage::operator=(other);
    copy(other);
    return *this;
}

void SIPChallengeCall::copy(const SIPChallengeCall& other)
{
}

void SIPChallengeCall::parsimPack(cCommBuffer *b)
{
    ::BaseCallMessage::parsimPack(b);
}

void SIPChallengeCall::parsimUnpack(cCommBuffer *b)
{
    ::BaseCallMessage::parsimUnpack(b);
}

class SIPChallengeCallDescriptor : public cClassDescriptor
{
  public:
    SIPChallengeCallDescriptor();
    virtual ~SIPChallengeCallDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(SIPChallengeCallDescriptor);

SIPChallengeCallDescriptor::SIPChallengeCallDescriptor() : cClassDescriptor("SIPChallengeCall", "BaseCallMessage")
{
}

SIPChallengeCallDescriptor::~SIPChallengeCallDescriptor()
{
}

bool SIPChallengeCallDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<SIPChallengeCall *>(obj)!=NULL;
}

const char *SIPChallengeCallDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int SIPChallengeCallDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount(object) : 0;
}

unsigned int SIPChallengeCallDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return 0;
}

const char *SIPChallengeCallDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

int SIPChallengeCallDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *SIPChallengeCallDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

const char *SIPChallengeCallDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int SIPChallengeCallDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    SIPChallengeCall *pp = (SIPChallengeCall *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string SIPChallengeCallDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    SIPChallengeCall *pp = (SIPChallengeCall *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool SIPChallengeCallDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    SIPChallengeCall *pp = (SIPChallengeCall *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *SIPChallengeCallDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

void *SIPChallengeCallDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    SIPChallengeCall *pp = (SIPChallengeCall *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(SIPChallengeResponse);

SIPChallengeResponse::SIPChallengeResponse(const char *name, int kind) : ::BaseResponseMessage(name,kind)
{
    this->identifier_var = 0;
}

SIPChallengeResponse::SIPChallengeResponse(const SIPChallengeResponse& other) : ::BaseResponseMessage(other)
{
    copy(other);
}

SIPChallengeResponse::~SIPChallengeResponse()
{
}

SIPChallengeResponse& SIPChallengeResponse::operator=(const SIPChallengeResponse& other)
{
    if (this==&other) return *this;
    ::BaseResponseMessage::operator=(other);
    copy(other);
    return *this;
}

void SIPChallengeResponse::copy(const SIPChallengeResponse& other)
{
    this->identifier_var = other.identifier_var;
}

void SIPChallengeResponse::parsimPack(cCommBuffer *b)
{
    ::BaseResponseMessage::parsimPack(b);
    doPacking(b,this->identifier_var);
}

void SIPChallengeResponse::parsimUnpack(cCommBuffer *b)
{
    ::BaseResponseMessage::parsimUnpack(b);
    doUnpacking(b,this->identifier_var);
}

const char * SIPChallengeResponse::getIdentifier() const
{
    return identifier_var.c_str();
}

void SIPChallengeResponse::setIdentifier(const char * identifier)
{
    this->identifier_var = identifier;
}

class SIPChallengeResponseDescriptor : public cClassDescriptor
{
  public:
    SIPChallengeResponseDescriptor();
    virtual ~SIPChallengeResponseDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(SIPChallengeResponseDescriptor);

SIPChallengeResponseDescriptor::SIPChallengeResponseDescriptor() : cClassDescriptor("SIPChallengeResponse", "BaseResponseMessage")
{
}

SIPChallengeResponseDescriptor::~SIPChallengeResponseDescriptor()
{
}

bool SIPChallengeResponseDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<SIPChallengeResponse *>(obj)!=NULL;
}

const char *SIPChallengeResponseDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int SIPChallengeResponseDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int SIPChallengeResponseDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *SIPChallengeResponseDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "identifier",
    };
    return (field>=0 && field<1) ? fieldNames[field] : NULL;
}

int SIPChallengeResponseDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='i' && strcmp(fieldName, "identifier")==0) return base+0;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *SIPChallengeResponseDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "string",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : NULL;
}

const char *SIPChallengeResponseDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int SIPChallengeResponseDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    SIPChallengeResponse *pp = (SIPChallengeResponse *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string SIPChallengeResponseDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    SIPChallengeResponse *pp = (SIPChallengeResponse *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->getIdentifier());
        default: return "";
    }
}

bool SIPChallengeResponseDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    SIPChallengeResponse *pp = (SIPChallengeResponse *)object; (void)pp;
    switch (field) {
        case 0: pp->setIdentifier((value)); return true;
        default: return false;
    }
}

const char *SIPChallengeResponseDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    };
}

void *SIPChallengeResponseDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    SIPChallengeResponse *pp = (SIPChallengeResponse *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


