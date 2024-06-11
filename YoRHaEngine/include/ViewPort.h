#pragma once
#include "PreRequisites.h"

class Window;
class DeviceContext;

class ViewPort
{
public:
	ViewPort() = default;
	~ViewPort() = default;

	void init(Window window);

	void update();

	void render(DeviceContext& deviceContext);

	void destroy();

public:
	D3D11_VIEWPORT m_viewPort;
};

