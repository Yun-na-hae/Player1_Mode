#pragma once
class Arrow_piece
{
public:
	CString strImagePath;
	Arrow_piece(int direction);
	~Arrow_piece();
	
	CImage GetImage();
	int GetDirection();
	void SetCorrectStatus();
	void SetWrongStatus();


private:
	CImage m_arrow_img;
	int m_direction;
	int m_status = 0; // 0 normal, 1 correct, 2 wrong

public:
	void LoadArrowImage();
	int GetArrowStatus();
};

