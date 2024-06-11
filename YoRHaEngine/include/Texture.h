#pragma once
#include "PreRequisites.h"


class Device;
class DeviceContext;


class Texture
{
public:
	Texture() = default;
	~Texture() = default;
	/// <summary>
	/// Brief: Crea una textura apartir de una imagen (.dds) desde nuestro ordenador
	/// </summary>
	/// <param name="device">LLamamos al device para poder generar los recursos en memoria. </param>
	/// <param name="textureName">Almacenamos el nombre de la textura, para cargarla desde memoria. </param>
	HRESULT
	init(Device device, std::string textureName);


				
	/// <summary>
	/// Brief:This method is responsible for creating a 2D Texture from the data provided
	/// by the developer.
	/// </summary>
	/// <param name="device">It is in charge of providing the resources to create the 2D Texture. </param>
	/// <param name="width">It will take the width of our window. </param>
	/// <param name="height">It will take the height of our window. </param>
	/// <param name="Format">It is a classifier that will allow bit spaces to be created correctly</param>
	/// <param name="BindFlags"></param>
	void init(Device device,
		unsigned int width,
		unsigned int height,
		DXGI_FORMAT Format,
		unsigned int BindFlags);

	/// <summary>
	/// Brief: This Method is in charge of updating the logic of the texture.
	/// </summary>
	void update();

	/// <summary>
	/// Brief: This method is in charge of drawing the resources on the screen.(only if necessary)
	/// </summary>
	/// <param name="deviceContext">It is in charge of assigning resources to be used.</param>
	/// <param name="StartSlot">It is in charge of assigning the starting point in memory</param>
	/// We recommend checking that it is not spliced?? in memory whit other resources.
	void render(DeviceContext & deviceContext,
				unsigned int StartSlot,
				unsigned int NumViews);

	/// <summary>
	/// Brief: This method is in charge of releasing the resources stored in the class's memory.
	/// </summary>
	void destroy();

public:
	// This variable is in charge of handle a texture resource as data.
	ID3D11Texture2D* m_texture = nullptr;

	//This variable is in charge of handle a texture resource as image data.
	ID3D11ShaderResourceView* m_textureFromImg;
};




