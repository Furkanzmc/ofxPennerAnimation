#include "ofxPennerAnimation.h"

ofxPennerAnimation::ofxPennerAnimation()
    : m_IsPaused(false)
    , m_IsAnimating(false)
    , m_EasingType(PENNER_EASING::LINEAR)
    , m_RepeatType(REPEAT::PLAY_ONCE)
    , m_RepeatCount(0)
    , m_RemainingRepeat(0)
    , m_PlayCount(0)
    , m_Duration(1.f)
    , m_DelayTime(0.f)
    , m_Time(0.f)
    , m_Beginning(0.f)
    , m_Change(0.f)
    , m_To(0.f)
    , m_CurrentValue(0.f)
{

}

ofxPennerAnimation::~ofxPennerAnimation()
{

}

void ofxPennerAnimation::reset(float value)
{
    m_IsPaused = false;
    m_EasingType = PENNER_EASING::LINEAR;
    m_RepeatCount = 0;
    m_PlayCount = 0;
    m_Duration = 1.f;
    m_Beginning = 0.f;
    m_Change = 0.f;
    m_CurrentValue = value;
    m_PlayCount = 0;
    m_RemainingRepeat = 0;
}

void ofxPennerAnimation::update(const float &dt)
{
    if (m_IsAnimating == false) {
        return;
    }

    if (m_DelayTime > 0.f) {
        m_DelayTime -= dt;
        return;
    }

    if (m_Time > m_Duration && m_IsAnimating) {
        if (m_RepeatType == REPEAT::LOOP) {
            animate(m_Beginning, m_To);
        }
        else if (m_RepeatType == REPEAT::LOOP_BACK_AND_FORTH) {
            animate(m_To, m_Beginning);
        }
        else if (m_RemainingRepeat > 0) {
            if (m_RepeatType == REPEAT::LOOP_BACK_AND_FORTH_ONCE) {
                animate(m_To, m_Beginning);
                m_RemainingRepeat = 0;
                m_RepeatCount = 0;
                return;
            }
            else if (m_RepeatType == REPEAT::LOOP_BACK_AND_FORTH_N_TIMES) {
                animate(m_To, m_Beginning);
            }
            else if (m_RepeatType == REPEAT::PLAY_N_TIMES) {
                animate(m_Beginning, m_To);
            }
            m_RemainingRepeat--;
        }
        m_IsAnimating = false;
        return;
    }

    m_Time += dt;
    m_PlayCount++;
    //BACK
    if (m_EasingType == PENNER_EASING::BACK_IN) {
        m_CurrentValue = ofxPennerEasing::Back::easeIn(m_Time, m_Beginning, m_Change, m_Duration);
    }
    else if (m_EasingType == PENNER_EASING::BACK_OUT) {
        m_CurrentValue = ofxPennerEasing::Back::easeOut(m_Time, m_Beginning, m_Change, m_Duration);
    }
    else if (m_EasingType == PENNER_EASING::BACK_IN_OUT) {
        m_CurrentValue = ofxPennerEasing::Back::easeInOut(m_Time, m_Beginning, m_Change, m_Duration);
    }
    //BOUNCE
    else if (m_EasingType == PENNER_EASING::BOUNCE_IN) {
        m_CurrentValue = ofxPennerEasing::Bounce::easeIn(m_Time, m_Beginning, m_Change, m_Duration);
    }
    else if (m_EasingType == PENNER_EASING::BOUNCE_OUT) {
        m_CurrentValue = ofxPennerEasing::Bounce::easeOut(m_Time, m_Beginning, m_Change, m_Duration);
    }
    else if (m_EasingType == PENNER_EASING::BOUNCE_IN_OUT) {
        m_CurrentValue = ofxPennerEasing::Bounce::easeInOut(m_Time, m_Beginning, m_Change, m_Duration);
    }
    //CIRC
    else if (m_EasingType == PENNER_EASING::CIRC_IN) {
        m_CurrentValue = ofxPennerEasing::Circ::easeIn(m_Time, m_Beginning, m_Change, m_Duration);
    }
    else if (m_EasingType == PENNER_EASING::CIRC_OUT) {
        m_CurrentValue = ofxPennerEasing::Circ::easeOut(m_Time, m_Beginning, m_Change, m_Duration);
    }
    else if (m_EasingType == PENNER_EASING::CIRC_IN_OUT) {
        m_CurrentValue = ofxPennerEasing::Circ::easeInOut(m_Time, m_Beginning, m_Change, m_Duration);
    }
    //CUBIC
    else if (m_EasingType == PENNER_EASING::CUBIC_IN) {
        m_CurrentValue = ofxPennerEasing::Cubic::easeIn(m_Time, m_Beginning, m_Change, m_Duration);
    }
    else if (m_EasingType == PENNER_EASING::CUBIC_OUT) {
        m_CurrentValue = ofxPennerEasing::Cubic::easeOut(m_Time, m_Beginning, m_Change, m_Duration);
    }
    else if (m_EasingType == PENNER_EASING::CUBIC_IN_OUT) {
        m_CurrentValue = ofxPennerEasing::Cubic::easeInOut(m_Time, m_Beginning, m_Change, m_Duration);
    }
    //ELASTIC
    else if (m_EasingType == PENNER_EASING::ELASTIC_IN) {
        m_CurrentValue = ofxPennerEasing::Elastic::easeIn(m_Time, m_Beginning, m_Change, m_Duration);
    }
    else if (m_EasingType == PENNER_EASING::ELASTIC_OUT) {
        m_CurrentValue = ofxPennerEasing::Elastic::easeOut(m_Time, m_Beginning, m_Change, m_Duration);
    }
    else if (m_EasingType == PENNER_EASING::ELASTIC_IN_OUT) {
        m_CurrentValue = ofxPennerEasing::Elastic::easeInOut(m_Time, m_Beginning, m_Change, m_Duration);
    }
    //EXPO
    else if (m_EasingType == PENNER_EASING::EXPO_IN) {
        m_CurrentValue = ofxPennerEasing::Expo::easeIn(m_Time, m_Beginning, m_Change, m_Duration);
    }
    else if (m_EasingType == PENNER_EASING::EXPO_OUT) {
        m_CurrentValue = ofxPennerEasing::Expo::easeOut(m_Time, m_Beginning, m_Change, m_Duration);
    }
    else if (m_EasingType == PENNER_EASING::EXPO_IN_OUT) {
        m_CurrentValue = ofxPennerEasing::Expo::easeInOut(m_Time, m_Beginning, m_Change, m_Duration);
    }
    //LINEAR
    else if (m_EasingType == PENNER_EASING::LINEAR) {
        m_CurrentValue = ofxPennerEasing::Linear::ease(m_Time, m_Beginning, m_Change, m_Duration);
    }
    //QUAD
    else if (m_EasingType == PENNER_EASING::QUAD_IN) {
        m_CurrentValue = ofxPennerEasing::Quad::easeIn(m_Time, m_Beginning, m_Change, m_Duration);
    }
    else if (m_EasingType == PENNER_EASING::QUAD_OUT) {
        m_CurrentValue = ofxPennerEasing::Quad::easeOut(m_Time, m_Beginning, m_Change, m_Duration);
    }
    else if (m_EasingType == PENNER_EASING::QUAD_IN_OUT) {
        m_CurrentValue = ofxPennerEasing::Quad::easeInOut(m_Time, m_Beginning, m_Change, m_Duration);
    }
    //QUART
    else if (m_EasingType == PENNER_EASING::QUART_IN) {
        m_CurrentValue = ofxPennerEasing::Quart::easeIn(m_Time, m_Beginning, m_Change, m_Duration);
    }
    else if (m_EasingType == PENNER_EASING::QUART_OUT) {
        m_CurrentValue = ofxPennerEasing::Quart::easeOut(m_Time, m_Beginning, m_Change, m_Duration);
    }
    else if (m_EasingType == PENNER_EASING::QUART_IN_OUT) {
        m_CurrentValue = ofxPennerEasing::Quart::easeInOut(m_Time, m_Beginning, m_Change, m_Duration);
    }
    //QUINT
    else if (m_EasingType == PENNER_EASING::QUINT_IN) {
        m_CurrentValue = ofxPennerEasing::Quint::easeIn(m_Time, m_Beginning, m_Change, m_Duration);
    }
    else if (m_EasingType == PENNER_EASING::QUINT_OUT) {
        m_CurrentValue = ofxPennerEasing::Quint::easeOut(m_Time, m_Beginning, m_Change, m_Duration);
    }
    else if (m_EasingType == PENNER_EASING::QUINT_IN_OUT) {
        m_CurrentValue = ofxPennerEasing::Quint::easeInOut(m_Time, m_Beginning, m_Change, m_Duration);
    }
    //SINE
    else if (m_EasingType == PENNER_EASING::SINE_IN) {
        m_CurrentValue = ofxPennerEasing::Sine::easeIn(m_Time, m_Beginning, m_Change, m_Duration);
    }
    else if (m_EasingType == PENNER_EASING::SINE_OUT) {
        m_CurrentValue = ofxPennerEasing::Sine::easeOut(m_Time, m_Beginning, m_Change, m_Duration);
    }
    else if (m_EasingType == PENNER_EASING::SINE_IN_OUT) {
        m_CurrentValue = ofxPennerEasing::Sine::easeInOut(m_Time, m_Beginning, m_Change, m_Duration);
    }
}

void ofxPennerAnimation::animate(float from, float to)
{
    m_IsAnimating = true;
    m_CurrentValue = 0.f;
    m_Time = 0.f;
    m_Beginning = from;
    m_Change = to - from;
    m_To = to;
    if (m_RepeatType == REPEAT::PLAY_ONCE || m_RepeatType == REPEAT::LOOP_BACK_AND_FORTH_ONCE || m_RemainingRepeat == 0) {
        m_PlayCount = 0;
        m_RemainingRepeat = m_RepeatCount;
    }
}

void ofxPennerAnimation::animateAfterDelay(float delay, float from, float to)
{
    m_IsAnimating = true;
    m_CurrentValue = 0;
    m_Time = 0;
    m_DelayTime = delay;
    m_Beginning = from;
    m_Change = to - from;
    m_To = to;
    if (m_RepeatType == REPEAT::PLAY_ONCE || m_RepeatType == REPEAT::LOOP_BACK_AND_FORTH_ONCE || m_RemainingRepeat == 0) {
        m_PlayCount = 0;
        m_RemainingRepeat = m_RepeatCount;
    }
}

void ofxPennerAnimation::pause()
{
    m_IsPaused = true;
}

void ofxPennerAnimation::resume()
{
    m_IsPaused = false;
}

void ofxPennerAnimation::setEasingType(PENNER_EASING type)
{
    m_EasingType = type;
}

void ofxPennerAnimation::setRepeatType(REPEAT repeat)
{
    m_RepeatType = repeat;
}

void ofxPennerAnimation::setRepeatCount(int count)
{
    m_RepeatCount = count - 1;
    m_RemainingRepeat = m_RepeatCount;
}

void ofxPennerAnimation::setDuration(float seconds)
{
    m_Duration = seconds;
}

void ofxPennerAnimation::setDelayTime(float delay)
{
    m_DelayTime = delay;
}

unsigned int ofxPennerAnimation::getPlayCount() const
{
    return m_PlayCount;
}

unsigned int ofxPennerAnimation::getRepeatCount() const
{
    return m_RepeatCount;
}

PENNER_EASING ofxPennerAnimation::getEasingType() const
{
    return m_EasingType;
}

REPEAT ofxPennerAnimation::getRepeatType() const
{
    return m_RepeatType;
}

float ofxPennerAnimation::getDuration() const
{
    return m_Duration;
}

bool ofxPennerAnimation::isAnimating() const
{
    return m_IsAnimating;
}

float ofxPennerAnimation::getCurrentValue() const
{
    return m_CurrentValue;
}
