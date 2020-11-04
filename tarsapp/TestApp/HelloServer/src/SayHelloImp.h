#ifndef _SayHelloImp_H_
#define _SayHelloImp_H_

#include "servant/Application.h"
#include "SayHello.h"

/**
 *
 *
 */
class SayHelloImp : public TestApp::SayHello
{
public:
    /**
     *
     */
    virtual ~SayHelloImp() {}

    /**
     *
     */
    virtual void initialize();

    /**
     *
     */
    virtual void destroy();

    /**
     *
     */
    virtual int test(tars::TarsCurrentPtr current) { return 0;};
};
/////////////////////////////////////////////////////
#endif
