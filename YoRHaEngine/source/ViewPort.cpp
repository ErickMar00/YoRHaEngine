#include "ViewPort.h"
#include "Window.h"
#include "DeviceContext.h"


void ViewPort::init(Window window)
{
    if (window.m_hWnd == nullptr) 
    {
        ERROR("ViewPort", "init", "CHECK FOR Window window")
            exit(1);
    }
    m_viewPort.Width = (float)window.m_width;
    m_viewPort.Height = (float)window.m_height;
    m_viewPort.MinDepth = 0.0f;
    m_viewPort.MaxDepth = 1.0f;
    m_viewPort.TopLeftX = 0;
    m_viewPort.TopLeftY = 0;
}

void ViewPort::update()
{
}

void ViewPort::render(DeviceContext& deviceContext)
{
    deviceContext.RSSetViewports(1, &m_viewPort);
}

void ViewPort::destroy()
{
}
