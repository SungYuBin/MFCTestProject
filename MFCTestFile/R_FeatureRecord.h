
#include<list>
#include"F_ATTR.h"
class R_FeatureRecord
{
public:
	R_FeatureRecord(void);
	~R_FeatureRecord(void);

public:
	std::list<F_ATTR*> m_attr;
	int m_scaleMin;
	int m_scaleMax;
	int m_bShownAllScale;

	int m_displayPriority;
	int m_viewingGroup;
	int m_displayCategory;
	int m_radarOver;
	bool m_hasText;
};
