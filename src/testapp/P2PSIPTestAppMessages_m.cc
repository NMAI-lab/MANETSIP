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

Register_Class(SIPRegisterCall);

SIPRegisterCall::SIPRegisterCall(const char *name, int kind) : ::BaseCallMessage(name,kind)
{
    this->identifier_var = 0;
}

SIPRegisterCall::SIPRegisterCall(const SIPRegisterCall& other) : ::BaseCallMessage(other)
{
    copy(other);
}

SIPRegisterCall::~SIPRegisterCall()
{
}

SIPRegisterCall& SIPRegisterCall::operator=(const SIPRegisterCall& other)
{
    if (this==&other) return *this;
    ::BaseCallMessage::operator=(other);
    copy(other);
    return *this;
}

void SIPRegisterCall::copy(const SIPRegisterCall& other)
{
    this->identifier_var = other.identifier_var;
    this->address_var = other.address_var;
}

void SIPRegisterCall::parsimPack(cCommBuffer *b)
{
    ::BaseCallMessage::parsimPack(b);
    doPacking(b,this->identifier_var);
    doPacking(b,this->address_var);
}

void SIPRegisterCall::parsimUnpack(cCommBuffer *b)
{
    ::BaseCallMessage::parsimUnpack(b);
    doUnpacking(b,this->identifier_var);
    doUnpacking(b,this->address_var);
}

const char * SIPRegisterCall::getIdentifier() const
{
    return identifier_var.c_str();
}

void SIPRegisterCall::setIdentifier(const char * identifier)
{
    this->identifier_var = identifier;
}

ManetAddress& SIPRegisterCall::getAddress()
{
    return address_var;
}

void SIPRegisterCall::setAddress(const ManetAddress& address)
{
    this->address_var = address;
}

class SIPRegisterCallDescriptor : public cClassDescriptor
{
  public:
    SIPRegisterCallDescriptor();
    virtual ~SIPRegisterCallDescriptor();

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

Register_ClassDescriptor(SIPRegisterCallDescriptor);

SIPRegisterCallDescriptor::SIPRegisterCallDescriptor() : cClassDescriptor("SIPRegisterCall", "BaseCallMessage")
{
}

SIPRegisterCallDescriptor::~SIPRegisterCallDescriptor()
{
}

bool SIPRegisterCallDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<SIPRegisterCall *>(obj)!=NULL;
}

const char *SIPRegisterCallDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int SIPRegisterCallDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount(object) : 2;
}

unsigned int SIPRegisterCallDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *SIPRegisterCallDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "identifier",
        "address",
    };
    return (field>=0 && field<2) ? fieldNames[field] : NULL;
}

int SIPRegisterCallDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='i' && strcmp(fieldName, "identifier")==0) return base+0;
    if (fieldName[0]=='a' && strcmp(fieldName, "address")==0) return base+1;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *SIPRegisterCallDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "string",
        "ManetAddress",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : NULL;
}

const char *SIPRegisterCallDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int SIPRegisterCallDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    SIPRegisterCall *pp = (SIPRegisterCall *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string SIPRegisterCallDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    SIPRegisterCall *pp = (SIPRegisterCall *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->getIdentifier());
        case 1: {std::stringstream out; out << pp->getAddress(); return out.str();}
        default: return "";
    }
}

bool SIPRegisterCallDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    SIPRegisterCall *pp = (SIPRegisterCall *)object; (void)pp;
    switch (field) {
        case 0: pp->setIdentifier((value)); return true;
        default: return false;
    }
}

const char *SIPRegisterCallDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 1: return opp_typename(typeid(ManetAddress));
        default: return NULL;
    };
}

void *SIPRegisterCallDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    SIPRegisterCall *pp = (SIPRegisterCall *)object; (void)pp;
    switch (field) {
        case 1: return (void *)(&pp->getAddress()); break;
        default: return NULL;
    }
}

Register_Class(SIPRegisterResponse);

SIPRegisterResponse::SIPRegisterResponse(const char *name, int kind) : ::BaseResponseMessage(name,kind)
{
    this->identifier_var = 0;
    this->isSuccess_var = 0;
}

SIPRegisterResponse::SIPRegisterResponse(const SIPRegisterResponse& other) : ::BaseResponseMessage(other)
{
    copy(other);
}

SIPRegisterResponse::~SIPRegisterResponse()
{
}

SIPRegisterResponse& SIPRegisterResponse::operator=(const SIPRegisterResponse& other)
{
    if (this==&other) return *this;
    ::BaseResponseMessage::operator=(other);
    copy(other);
    return *this;
}

void SIPRegisterResponse::copy(const SIPRegisterResponse& other)
{
    this->identifier_var = other.identifier_var;
    this->address_var = other.address_var;
    this->isSuccess_var = other.isSuccess_var;
}

void SIPRegisterResponse::parsimPack(cCommBuffer *b)
{
    ::BaseResponseMessage::parsimPack(b);
    doPacking(b,this->identifier_var);
    doPacking(b,this->address_var);
    doPacking(b,this->isSuccess_var);
}

void SIPRegisterResponse::parsimUnpack(cCommBuffer *b)
{
    ::BaseResponseMessage::parsimUnpack(b);
    doUnpacking(b,this->identifier_var);
    doUnpacking(b,this->address_var);
    doUnpacking(b,this->isSuccess_var);
}

const char * SIPRegisterResponse::getIdentifier() const
{
    return identifier_var.c_str();
}

void SIPRegisterResponse::setIdentifier(const char * identifier)
{
    this->identifier_var = identifier;
}

ManetAddress& SIPRegisterResponse::getAddress()
{
    return address_var;
}

void SIPRegisterResponse::setAddress(const ManetAddress& address)
{
    this->address_var = address;
}

bool SIPRegisterResponse::getIsSuccess() const
{
    return isSuccess_var;
}

void SIPRegisterResponse::setIsSuccess(bool isSuccess)
{
    this->isSuccess_var = isSuccess;
}

class SIPRegisterResponseDescriptor : public cClassDescriptor
{
  public:
    SIPRegisterResponseDescriptor();
    virtual ~SIPRegisterResponseDescriptor();

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

Register_ClassDescriptor(SIPRegisterResponseDescriptor);

SIPRegisterResponseDescriptor::SIPRegisterResponseDescriptor() : cClassDescriptor("SIPRegisterResponse", "BaseResponseMessage")
{
}

SIPRegisterResponseDescriptor::~SIPRegisterResponseDescriptor()
{
}

bool SIPRegisterResponseDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<SIPRegisterResponse *>(obj)!=NULL;
}

const char *SIPRegisterResponseDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int SIPRegisterResponseDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount(object) : 3;
}

unsigned int SIPRegisterResponseDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *SIPRegisterResponseDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "identifier",
        "address",
        "isSuccess",
    };
    return (field>=0 && field<3) ? fieldNames[field] : NULL;
}

int SIPRegisterResponseDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='i' && strcmp(fieldName, "identifier")==0) return base+0;
    if (fieldName[0]=='a' && strcmp(fieldName, "address")==0) return base+1;
    if (fieldName[0]=='i' && strcmp(fieldName, "isSuccess")==0) return base+2;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *SIPRegisterResponseDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "string",
        "ManetAddress",
        "bool",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : NULL;
}

const char *SIPRegisterResponseDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int SIPRegisterResponseDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    SIPRegisterResponse *pp = (SIPRegisterResponse *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string SIPRegisterResponseDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    SIPRegisterResponse *pp = (SIPRegisterResponse *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->getIdentifier());
        case 1: {std::stringstream out; out << pp->getAddress(); return out.str();}
        case 2: return bool2string(pp->getIsSuccess());
        default: return "";
    }
}

bool SIPRegisterResponseDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    SIPRegisterResponse *pp = (SIPRegisterResponse *)object; (void)pp;
    switch (field) {
        case 0: pp->setIdentifier((value)); return true;
        case 2: pp->setIsSuccess(string2bool(value)); return true;
        default: return false;
    }
}

const char *SIPRegisterResponseDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 1: return opp_typename(typeid(ManetAddress));
        default: return NULL;
    };
}

void *SIPRegisterResponseDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    SIPRegisterResponse *pp = (SIPRegisterResponse *)object; (void)pp;
    switch (field) {
        case 1: return (void *)(&pp->getAddress()); break;
        default: return NULL;
    }
}

Register_Class(SIPResolveCall);

SIPResolveCall::SIPResolveCall(const char *name, int kind) : ::BaseCallMessage(name,kind)
{
    this->identifier_var = 0;
}

SIPResolveCall::SIPResolveCall(const SIPResolveCall& other) : ::BaseCallMessage(other)
{
    copy(other);
}

SIPResolveCall::~SIPResolveCall()
{
}

SIPResolveCall& SIPResolveCall::operator=(const SIPResolveCall& other)
{
    if (this==&other) return *this;
    ::BaseCallMessage::operator=(other);
    copy(other);
    return *this;
}

void SIPResolveCall::copy(const SIPResolveCall& other)
{
    this->identifier_var = other.identifier_var;
}

void SIPResolveCall::parsimPack(cCommBuffer *b)
{
    ::BaseCallMessage::parsimPack(b);
    doPacking(b,this->identifier_var);
}

void SIPResolveCall::parsimUnpack(cCommBuffer *b)
{
    ::BaseCallMessage::parsimUnpack(b);
    doUnpacking(b,this->identifier_var);
}

const char * SIPResolveCall::getIdentifier() const
{
    return identifier_var.c_str();
}

void SIPResolveCall::setIdentifier(const char * identifier)
{
    this->identifier_var = identifier;
}

class SIPResolveCallDescriptor : public cClassDescriptor
{
  public:
    SIPResolveCallDescriptor();
    virtual ~SIPResolveCallDescriptor();

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

Register_ClassDescriptor(SIPResolveCallDescriptor);

SIPResolveCallDescriptor::SIPResolveCallDescriptor() : cClassDescriptor("SIPResolveCall", "BaseCallMessage")
{
}

SIPResolveCallDescriptor::~SIPResolveCallDescriptor()
{
}

bool SIPResolveCallDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<SIPResolveCall *>(obj)!=NULL;
}

const char *SIPResolveCallDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int SIPResolveCallDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int SIPResolveCallDescriptor::getFieldTypeFlags(void *object, int field) const
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

const char *SIPResolveCallDescriptor::getFieldName(void *object, int field) const
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

int SIPResolveCallDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='i' && strcmp(fieldName, "identifier")==0) return base+0;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *SIPResolveCallDescriptor::getFieldTypeString(void *object, int field) const
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

const char *SIPResolveCallDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int SIPResolveCallDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    SIPResolveCall *pp = (SIPResolveCall *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string SIPResolveCallDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    SIPResolveCall *pp = (SIPResolveCall *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->getIdentifier());
        default: return "";
    }
}

bool SIPResolveCallDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    SIPResolveCall *pp = (SIPResolveCall *)object; (void)pp;
    switch (field) {
        case 0: pp->setIdentifier((value)); return true;
        default: return false;
    }
}

const char *SIPResolveCallDescriptor::getFieldStructName(void *object, int field) const
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

void *SIPResolveCallDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    SIPResolveCall *pp = (SIPResolveCall *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(SIPResolveResponse);

SIPResolveResponse::SIPResolveResponse(const char *name, int kind) : ::BaseResponseMessage(name,kind)
{
    this->identifier_var = 0;
    this->isSuccess_var = 0;
}

SIPResolveResponse::SIPResolveResponse(const SIPResolveResponse& other) : ::BaseResponseMessage(other)
{
    copy(other);
}

SIPResolveResponse::~SIPResolveResponse()
{
}

SIPResolveResponse& SIPResolveResponse::operator=(const SIPResolveResponse& other)
{
    if (this==&other) return *this;
    ::BaseResponseMessage::operator=(other);
    copy(other);
    return *this;
}

void SIPResolveResponse::copy(const SIPResolveResponse& other)
{
    this->identifier_var = other.identifier_var;
    this->address_var = other.address_var;
    this->isSuccess_var = other.isSuccess_var;
}

void SIPResolveResponse::parsimPack(cCommBuffer *b)
{
    ::BaseResponseMessage::parsimPack(b);
    doPacking(b,this->identifier_var);
    doPacking(b,this->address_var);
    doPacking(b,this->isSuccess_var);
}

void SIPResolveResponse::parsimUnpack(cCommBuffer *b)
{
    ::BaseResponseMessage::parsimUnpack(b);
    doUnpacking(b,this->identifier_var);
    doUnpacking(b,this->address_var);
    doUnpacking(b,this->isSuccess_var);
}

const char * SIPResolveResponse::getIdentifier() const
{
    return identifier_var.c_str();
}

void SIPResolveResponse::setIdentifier(const char * identifier)
{
    this->identifier_var = identifier;
}

ManetAddress& SIPResolveResponse::getAddress()
{
    return address_var;
}

void SIPResolveResponse::setAddress(const ManetAddress& address)
{
    this->address_var = address;
}

bool SIPResolveResponse::getIsSuccess() const
{
    return isSuccess_var;
}

void SIPResolveResponse::setIsSuccess(bool isSuccess)
{
    this->isSuccess_var = isSuccess;
}

class SIPResolveResponseDescriptor : public cClassDescriptor
{
  public:
    SIPResolveResponseDescriptor();
    virtual ~SIPResolveResponseDescriptor();

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

Register_ClassDescriptor(SIPResolveResponseDescriptor);

SIPResolveResponseDescriptor::SIPResolveResponseDescriptor() : cClassDescriptor("SIPResolveResponse", "BaseResponseMessage")
{
}

SIPResolveResponseDescriptor::~SIPResolveResponseDescriptor()
{
}

bool SIPResolveResponseDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<SIPResolveResponse *>(obj)!=NULL;
}

const char *SIPResolveResponseDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int SIPResolveResponseDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount(object) : 3;
}

unsigned int SIPResolveResponseDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *SIPResolveResponseDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "identifier",
        "address",
        "isSuccess",
    };
    return (field>=0 && field<3) ? fieldNames[field] : NULL;
}

int SIPResolveResponseDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='i' && strcmp(fieldName, "identifier")==0) return base+0;
    if (fieldName[0]=='a' && strcmp(fieldName, "address")==0) return base+1;
    if (fieldName[0]=='i' && strcmp(fieldName, "isSuccess")==0) return base+2;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *SIPResolveResponseDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "string",
        "ManetAddress",
        "bool",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : NULL;
}

const char *SIPResolveResponseDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int SIPResolveResponseDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    SIPResolveResponse *pp = (SIPResolveResponse *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string SIPResolveResponseDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    SIPResolveResponse *pp = (SIPResolveResponse *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->getIdentifier());
        case 1: {std::stringstream out; out << pp->getAddress(); return out.str();}
        case 2: return bool2string(pp->getIsSuccess());
        default: return "";
    }
}

bool SIPResolveResponseDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    SIPResolveResponse *pp = (SIPResolveResponse *)object; (void)pp;
    switch (field) {
        case 0: pp->setIdentifier((value)); return true;
        case 2: pp->setIsSuccess(string2bool(value)); return true;
        default: return false;
    }
}

const char *SIPResolveResponseDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 1: return opp_typename(typeid(ManetAddress));
        default: return NULL;
    };
}

void *SIPResolveResponseDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    SIPResolveResponse *pp = (SIPResolveResponse *)object; (void)pp;
    switch (field) {
        case 1: return (void *)(&pp->getAddress()); break;
        default: return NULL;
    }
}


