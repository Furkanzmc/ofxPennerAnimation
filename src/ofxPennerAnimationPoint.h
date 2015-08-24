#ifndef OFXPENNERANIMATIONPOINT_H
#define OFXPENNERANIMATIONPOINT_H
#include "ofxPennerAnimation.h"
#include <array>

class ofxPennerAnimationPoint
{
public:
    ofxPennerAnimationPoint()
    {
        m_Animations[0] = new ofxPennerAnimation();
        m_Animations[1] = new ofxPennerAnimation();
        m_Animations[2] = new ofxPennerAnimation();
    }

    ~ofxPennerAnimationPoint()
    {
        if (m_Animations[0]) {
            delete m_Animations[0];
            m_Animations[0] = nullptr;
        }

        if (m_Animations[1]) {
            delete m_Animations[1];
            m_Animations[1] = nullptr;
        }

        if (m_Animations[2]) {
            delete m_Animations[2];
            m_Animations[2] = nullptr;
        }
    }

    void reset(const ofPoint &point = ofPoint(0, 0, 0))
    {
        m_Animations[0]->reset(point.x);
        m_Animations[1]->reset(point.y);
        m_Animations[2]->reset(point.z);
    }

    void update(const float &dt)
    {
        for (ofxPennerAnimation *anim : m_Animations) {
            anim->update(dt);
        }
    }

    void animate(ofPoint from, ofPoint to)
    {
        m_Animations[0]->animate(from.x, to.x);
        m_Animations[1]->animate(from.y, to.y);
        m_Animations[2]->animate(from.z, to.z);
    }

    void animateAfterDelay(float delay, ofPoint from, ofPoint to)
    {
        m_Animations[0]->animateAfterDelay(delay, from.x, to.x);
        m_Animations[1]->animateAfterDelay(delay, from.y, to.y);
        m_Animations[2]->animateAfterDelay(delay, from.z, to.z);
    }

    void pause()
    {
        for (ofxPennerAnimation *anim : m_Animations) {
            anim->pause();
        }
    }

    void resume()
    {
        for (ofxPennerAnimation *anim : m_Animations) {
            anim->resume();
        }
    }

    void setEasingType(PENNER_EASING type)
    {
        for (ofxPennerAnimation *anim : m_Animations) {
            anim->setEasingType(type);
        }
    }

    void setRepeatType(REPEAT repeat)
    {
        for (ofxPennerAnimation *anim : m_Animations) {
            anim->setRepeatType(repeat);
        }
    }

    void setRepeatCount(int count)
    {
        for (ofxPennerAnimation *anim : m_Animations) {
            anim->setRepeatCount(count);
        }
    }

    void setDuration(float seconds)
    {
        for (ofxPennerAnimation *anim : m_Animations) {
            anim->setDuration(seconds);
        }
    }

    void setDelayTime(float delay)
    {
        for (ofxPennerAnimation *anim : m_Animations) {
            anim->setDelayTime(delay);
        }
    }

    unsigned int getPlayCount() const
    {
        return m_Animations[0]->getPlayCount();
    }
    unsigned int getRepeatCount() const
    {
        return m_Animations[0]->getRepeatCount();
    }

    PENNER_EASING getEasingType() const
    {
        return m_Animations[0]->getEasingType();
    }

    REPEAT getRepeatType() const
    {
        return m_Animations[0]->getRepeatType();
    }

    float getDuration() const
    {
        return m_Animations[0]->getDuration();
    }

    ofPoint getCurrentPosition() const
    {
        return ofPoint(m_Animations[0]->getCurrentValue(), m_Animations[1]->getCurrentValue(), m_Animations[2]->getCurrentValue());
    }

    bool isAnimating() const
    {
        return m_Animations[0]->isAnimating();
    }

    void setPosition(const ofPoint &point)
    {
        m_Animations[0]->setCurrentValue(point.x);
        m_Animations[1]->setCurrentValue(point.y);
        m_Animations[2]->setCurrentValue(point.z);
    }

private:
    std::array<ofxPennerAnimation *, 3> m_Animations;
};

#endif // OFXPENNERANIMATIONPOINT_H
