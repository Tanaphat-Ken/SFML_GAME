#pragma once
class AttributeComponent
{
public:

	//Stats
	int hp;
	int hpMax;

	//Con / Des
	AttributeComponent();
	virtual ~AttributeComponent();

	//Functions

	void loseHP(const int hp);
	void gainHP(const int hp);

	const bool isDead() const;

	void updateStats(const bool reset);

};


