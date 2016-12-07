#include "stdafx.h"
#include "Arrow_piece.h"

//구조체 변수ap 선언

Arrow_piece::Arrow_piece(int direction)
{
	m_direction = direction;
	//CString strImagePath;
}


Arrow_piece::~Arrow_piece()
{
	m_arrow_img.Destroy();
}


CImage Arrow_piece::GetImage()
{
	return m_arrow_img;
}

int Arrow_piece::GetDirection()
{
	return m_direction;
}



//0왼 1오 2위 3아래
void Arrow_piece::SetCorrectStatus()
{
	m_status = 1;
}


void Arrow_piece::SetWrongStatus()
{
	m_status = 2;
}



void Arrow_piece::LoadArrowImage()
{
	m_arrow_img.Destroy();

	switch (m_direction) { //0왼 1오 2위 3아래
	case 0:
		switch (m_status) {
		case 0:
			strImagePath = _T("./res/b_arrow_left.png");
			break;
		case 1:
			strImagePath = _T("./res/g_arrow_left.png");
			break;
		case 2:
			strImagePath = _T("./res/r_arrow_left.png");
			break;
		}
		break;
	case 1:
		switch (m_status) {
		case 0:
			strImagePath = _T("./res/b_arrow_right.png");
			break;
		case 1:
			strImagePath = _T("./res/g_arrow_right.png");
			break;
		case 2:
			strImagePath = _T("./res/r_arrow_right.png");
			break;
		}
		break;
	case 2:
		switch (m_status) {
		case 0:
			strImagePath = _T("./res/b_arrow_up.png");
			break;
		case 1:
			strImagePath = _T("./res/g_arrow_up.png");
			break;
		case 2:
			strImagePath = _T("./res/r_arrow_up.png");
			break;
		}
		break;
	case 3:
		switch (m_status) {
		case 0:
			strImagePath = _T("./res/b_arrow_down.png");
			break;
		case 1:
			strImagePath = _T("./res/g_arrow_down.png");
			break;
		case 2:
			strImagePath = _T("./res/r_arrow_down.png");
			break;
		}
		break;
	default:
		break;
	}

	if (SUCCEEDED(m_arrow_img.Load(strImagePath))) {
		if (m_arrow_img.GetBPP() == 32)
		{
			unsigned char * pCol = 0;
			long w = m_arrow_img.GetWidth();
			long h = m_arrow_img.GetHeight();
			for (long y = 0; y < h; y++) {
				for (long x = 0; x < w; x++) {
					pCol = (unsigned char *)m_arrow_img.GetPixelAddress(x, y);
					unsigned char alpha = pCol[3];
					if (alpha != 255) {
						pCol[0] = ((pCol[0] * alpha) + 128) >> 8;
						pCol[1] = ((pCol[1] * alpha) + 128) >> 8;
						pCol[2] = ((pCol[2] * alpha) + 128) >> 8;

					}
				}
			}
		}
		m_arrow_img.SetHasAlphaChannel(true);
	}
}


int Arrow_piece::GetArrowStatus()
{
	return m_status;
}
