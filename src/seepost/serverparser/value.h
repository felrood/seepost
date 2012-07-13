#ifndef _INCLUDED_VALUE_H_
#define _INCLUDED_VALUE_H_

namespace Server {
struct Value
{
    enum Type
    {

        ID,
        STRING,
        BLOB,
        ENVELOPE
    };

    Type        d_type;
    unsigned    d_idx;
    std::string d_string;
    std::string d_msg;

    public:
        Value();
};

inline Value::Value()
:
d_type(ID),
d_idx(0)
{}

}

#endif
