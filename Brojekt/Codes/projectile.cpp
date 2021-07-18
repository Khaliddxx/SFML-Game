//
//  projectile.cpp
//
// Team Brojekt
//
// Khalid Mohamed
// Amr Selimy
// Tala Attiah
//
#include "projectile.h"

projectile::projectile()
{
    rect.setSize(sf::Vector2f(projectile_size,projectile_size));
    rect.setFillColor(sf::Color::Red);
    sprite.setTextureRect(sf::IntRect(0, 0, projectile_size, projectile_size));
    
}

void projectile::update()
{
    if (direction == 1) // Up
    {
        rect.move (0, -moveSpeed);
        sprite.setTextureRect(sf::IntRect(counterAnimation*projectile_size, 3*projectile_size, projectile_size, projectile_size));
        
    }
    else if (direction == 2) // Down
    {
        rect.move (0, moveSpeed);
        sprite.setTextureRect(sf::IntRect(counterAnimation*projectile_size, 0*projectile_size, projectile_size, projectile_size));
    }
    else if (direction == 3) // Left
    {
        rect.move (-moveSpeed, 0);
        sprite.setTextureRect(sf::IntRect(counterAnimation*projectile_size, 1*projectile_size, projectile_size, projectile_size));
    }
    else if (direction == 4) // Right
    {
        rect.move (moveSpeed, 0);
        sprite.setTextureRect(sf::IntRect(counterAnimation*projectile_size, 2*projectile_size, projectile_size, projectile_size));
        
    }

    counterlifetime++;
    
    if (counterlifetime >= lifetime)
    {
        destroy = true;
    }
    
    counterAnimation++;
    if(counterAnimation >= 2)
        counterAnimation = 0;
    
    // Sprite set at rect
    sprite.setPosition(rect.getPosition());
}
