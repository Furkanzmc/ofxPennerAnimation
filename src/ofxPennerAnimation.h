#ifndef OFXPENNERANIMATION_H
#define OFXPENNERANIMATION_H
#include "ofxPennerEasing.h"
#include "ofMain.h"

enum class REPEAT {
    PLAY_ONCE = 0,
    LOOP,
    LOOP_BACK_AND_FORTH,
    LOOP_BACK_AND_FORTH_ONCE,
    PLAY_N_TIMES,
    LOOP_BACK_AND_FORTH_N_TIMES
};

class ofxPennerAnimation
{
public:
    ofxPennerAnimation();
    ~ofxPennerAnimation();

    void reset(float value = 0.f);
    void update(const float &dt);

    void animate(float from, float to);
    void animateAfterDelay(float delay, float from, float to);

    void pause();
    void resume();

    void setEasingType(PENNER_EASING type);

    void setRepeatType(REPEAT repeat);
    void setRepeatCount(int count);
    void setDuration(float seconds);
    void setDelayTime(float delay);

    unsigned int getPlayCount() const;
    unsigned int getRepeatCount() const;
    PENNER_EASING getEasingType() const;
    REPEAT getRepeatType() const;
    float getDuration() const;
    bool isAnimating() const;

    float getCurrentValue() const;

private:
    bool m_IsPaused;
    PENNER_EASING m_EasingType;
    REPEAT m_RepeatType;
    unsigned int m_RepeatCount,
             m_RemainingRepeat,
             m_PlayCount;

    float m_Duration,
          m_DelayTime,
          m_Time,
          m_Beginning,
          m_Change,
          m_To,
          m_CurrentValue;
};

#endif // OFXPENNERANIMATION_H
