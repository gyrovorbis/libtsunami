/*
   Tsunami for KallistiOS ##version##

   chainanim.h

   Copyright (C) 2002 Megan Potter

*/

#ifndef __TSUNAMI_TRIG_CHAINANIM_H
#define __TSUNAMI_TRIG_CHAINANIM_H

#include "../trigger.h"
#include "../animation.h"
#include "../drawable.h"

class ChainAnimation : public Trigger {
public:
	// Constructor / Destructor
	ChainAnimation(Animation *na, Drawable * target = NULL) {
		m_newanim = na;
		m_target = target;
	}
	virtual ~ChainAnimation() {
	}

	// Called when we have reached the trigger point in the
	// given animation/drawable
	virtual void trigger(Drawable *t, Animation *a) {
		if (m_target)
			m_target->animAdd(m_newanim);
		else
			t->animAdd(m_newanim);
		Trigger::trigger(t, a);
	}

private:
	RefPtr<Animation>	m_newanim;
	RefPtr<Drawable>	m_target;
};

#endif	/* __TSUNAMI_TRIG_CHAINANIM_H */
