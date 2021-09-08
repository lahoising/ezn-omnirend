
#ifndef __EZN_OMNIREND_H__
#define __EZN_OMNIREND_H__

namespace ezn
{
    
class Omnirend
{
public:
    Omnirend();
    ~Omnirend();

    void AddWindow(void *windowHandle);
    void FrameBegin();
    void FrameEnd();
    void ClearFrame();
};

} // namespace ezn

#endif