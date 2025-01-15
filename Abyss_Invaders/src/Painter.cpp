#include "Painter.h"

void Painter::setActorsVector(ACTORS_VECTOR *actors, UI_ELEMENTS_ARRAY *elements)
{
	m_actors = actors;
	m_uiElements = elements;
	ready = true;
}

void Painter::paint()
{
    setUiElementsPos();

	for (sf::Text* element : *m_uiElements)
	{
		m_gameWindow->draw(*element);
	}

    for (std::shared_ptr<Actor> actor : *m_actors)
    {
        m_gameWindow->draw(*actor);
    }
}

bool Painter::isReady()
{
	return ready;
}

void Painter::setUiElementsPos()
{
    sf::Vector2u windowSize = m_gameWindow->getSize();
    float width = static_cast<float>(windowSize.x);
    float height = static_cast<float>(windowSize.y);
    sf::Text* element;

    // MODE positioning
    element = (*m_uiElements)[0];
    element->setPosition(0.5f * width - element->getGlobalBounds().width / 2, 0.02f * height);

    element = (*m_uiElements)[1];
    element->setPosition(0.5f * width - element->getGlobalBounds().width / 2, 0.06f * height);
    
    // SCORE positioning
    element = (*m_uiElements)[2];
    element->setPosition(0.15f * width, 0.02f * height);

    element = (*m_uiElements)[3];
    element->setPosition(0.165f * width, 0.06f * height);

    // HS positioning
    element = (*m_uiElements)[4];
    element->setPosition(0.85f * width - element->getGlobalBounds().width, 0.02f * height);

    element = (*m_uiElements)[5];
    element->setPosition(0.855f * width - element->getGlobalBounds().width, 0.06f * height);

    // LIVES positioning
    element = (*m_uiElements)[6];
    element->setPosition(0.1f * width, 0.92f * height - element->getGlobalBounds().height);

    element = (*m_uiElements)[7];
    element->setPosition(0.11f * width, 0.96f * height - element->getGlobalBounds().height);
}

