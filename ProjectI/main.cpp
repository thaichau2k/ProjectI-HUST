//  project I: tower of hanoi
// Nguyễn Ngọc Thái Châu - 20183869 
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <vector>
#include <cmath>

std::vector<sf::RectangleShape> disks;
int movecnt = 0;

// Hàm vẽ lại tháp, giá trị m là số lượng đĩa được nhập từ bàn phím, ctdl vector lưu trữ đĩa và cọc
void DrawTower(sf::RenderWindow& window, std::vector<sf::RectangleShape> disks, std::vector<sf::RectangleShape> rods, int m) {

    for (int i = 0; i < 6; i++) {
        window.draw(rods[i]);
    }

    for (int i = 0; i < m*3; i++) {
        window.draw(disks[i]);
    }
}


void DrawHeader(sf::RenderWindow& window, sf::Text Header, sf::Text sig, sf::Text moveCount) {
    Header.setCharacterSize(100);
    Header.setPosition(198.f, 30.f);
    moveCount.setString("Numbers of move: " + std::to_string(movecnt));
    window.draw(Header);
    window.draw(sig);
    window.draw(moveCount);
}


void tower(sf::RenderWindow& window, int m, int n, std::vector<sf::RectangleShape> rods,sf::Text Header,
    sf::Text sig, sf::Text moveCount, int x, int y, int z) {
    if (m == 1) { 
        movecnt++;
        window.clear();
        disks[3 * n - z].setFillColor(disks[3 * n - x].getFillColor());
        disks[3 * n - x].setFillColor(sf::Color::Transparent);
        sf::sleep(sf::seconds(0.5));
        DrawHeader(window, Header, sig, moveCount);
        DrawTower(window, disks, rods, n);
        window.display();  
        return;
    }

    tower(window, m - 1, n,  rods, Header, sig, moveCount, x, z, y);

    movecnt++;
    window.clear();
    disks[3 * n - 3 * m + 3 - z].setFillColor(disks[3 * (n - m + 1) - x].getFillColor());
    disks[3 * (n - m + 1) - x].setFillColor(sf::Color::Transparent);
    sf::sleep(sf::seconds(0.5));
    DrawHeader(window, Header, sig, moveCount);
    DrawTower(window, disks, rods, n);
    window.display();

    tower(window, m - 1, n, rods, Header, sig, moveCount, y, x, z);
}

int main()
{   
    // Tạo một của sổ "Tower Of HaNoi" có độ dài 900 pixels, độ cao 650 pixels  
    sf::RenderWindow window(sf::VideoMode(900, 650), "Tower Of HaNoi");

    // Create text
    // Lấy các font chữ lưu trên máy 
    sf::Font font1;
    if (!font1.loadFromFile("res/GrandHotel.otf")) {
        std::cout << "Error loading file" << std::endl;
        system("pause");
    }

    sf::Font font2;
    if (!font2.loadFromFile("res/Purchuse.ttf")) {
        std::cout << "Error loading file" << std::endl;
        system("pause");
    }

    sf::Text Header;
    Header.setFont(font1);
    Header.setString("Tower of Hanoi");
    Header.setCharacterSize(150);
    Header.setPosition(72.f, 50.f);

    sf::Text MoveCount;
    MoveCount.setFont(font1);
    MoveCount.setCharacterSize(30);
    MoveCount.setPosition(354.f, 230.f);

    sf::Text sig;
    sig.setFont(font1);
    sig.setCharacterSize(30);
    sig.setString("Nguyen Ngoc Thai Chau - 20183869");
    sig.setPosition(10.f, 10.f);


    sf::Text input;
    input.setFont(font2);
    input.setCharacterSize(50);
    input.setString("Enter number of disks (2-8)");
    input.setPosition(270.f, 450.f);

    // Create 3 row T shape
    sf::RectangleShape row1(sf::Vector2f(20.f, 320.f));
    row1.setPosition(165.f, 310.f);
    
    sf::RectangleShape row2(sf::Vector2f(20.f, 320.f));
    row2.setPosition(440.f, 310.f);
   
    sf::RectangleShape row3(sf::Vector2f(20.f, 320.f));
    row3.setPosition(715.f, 310.f);

    sf::RectangleShape base1(sf::Vector2f(250.f, 20.f));
    base1.setPosition(50.f, 630.f);

    sf::RectangleShape base2(sf::Vector2f(250.f, 20.f));
    base2.setPosition(325.f, 630.f);

    sf::RectangleShape base3(sf::Vector2f(250.f, 20.f));
    base3.setPosition(600.f, 630.f);

    std::vector<sf::RectangleShape> rods;
    rods.push_back(row1);
    rods.push_back(row2);
    rods.push_back(row3);
    rods.push_back(base1);
    rods.push_back(base2);
    rods.push_back(base3);

    for (int i = 0; i < 6;i++) {
        rods[i].setFillColor(sf::Color(210, 105, 30));
    }

    // Create disks
    sf::RectangleShape disk11(sf::Vector2f(230.f,40.f));
    disk11.setPosition(60.f, 590.f);

    sf::RectangleShape disk12(sf::Vector2f(210.f, 40.f));
    disk12.setPosition(70.f, 550.f);

    sf::RectangleShape disk13(sf::Vector2f(190.f, 40.f));
    disk13.setPosition(80.f, 510.f);

    sf::RectangleShape disk14(sf::Vector2f(170.f, 40.f));
    disk14.setPosition(90.f, 470.f);

    sf::RectangleShape disk15(sf::Vector2f(150.f, 40.f));
    disk15.setPosition(100.f, 430.f);

    sf::RectangleShape disk16(sf::Vector2f(130.f, 40.f));
    disk16.setPosition(110.f, 390.f);

    sf::RectangleShape disk17(sf::Vector2f(110.f, 40.f));
    disk17.setPosition(120.f, 350.f);

    sf::RectangleShape disk18(sf::Vector2f(90.f, 40.f));
    disk18.setPosition(130.f, 310.f);

    sf::RectangleShape disk21(sf::Vector2f(230.f, 40.f));
    disk21.setPosition(335.f, 590.f);

    sf::RectangleShape disk22(sf::Vector2f(210.f, 40.f));
    disk22.setPosition(345.f, 550.f);

    sf::RectangleShape disk23(sf::Vector2f(190.f, 40.f));
    disk23.setPosition(355.f, 510.f);

    sf::RectangleShape disk24(sf::Vector2f(170.f, 40.f));
    disk24.setPosition(365.f, 470.f);

    sf::RectangleShape disk25(sf::Vector2f(150.f, 40.f));
    disk25.setPosition(375.f, 430.f);

    sf::RectangleShape disk26(sf::Vector2f(130.f, 40.f));
    disk26.setPosition(385.f, 390.f);

    sf::RectangleShape disk27(sf::Vector2f(110.f, 40.f));
    disk27.setPosition(395.f, 350.f);

    sf::RectangleShape disk28(sf::Vector2f(90.f, 40.f));
    disk28.setPosition(405.f, 310.f);

    sf::RectangleShape disk31(sf::Vector2f(230.f, 40.f));
    disk31.setPosition(610.f, 590.f);

    sf::RectangleShape disk32(sf::Vector2f(210.f, 40.f));
    disk32.setPosition(620.f, 550.f);

    sf::RectangleShape disk33(sf::Vector2f(190.f, 40.f));
    disk33.setPosition(630.f, 510.f);

    sf::RectangleShape disk34(sf::Vector2f(170.f, 40.f));
    disk34.setPosition(640.f, 470.f);

    sf::RectangleShape disk35(sf::Vector2f(150.f, 40.f));
    disk35.setPosition(650.f, 430.f);

    sf::RectangleShape disk36(sf::Vector2f(130.f, 40.f));
    disk36.setPosition(660.f, 390.f);

    sf::RectangleShape disk37(sf::Vector2f(110.f, 40.f));
    disk37.setPosition(670.f, 350.f);

    sf::RectangleShape disk38(sf::Vector2f(90.f, 40.f));
    disk38.setPosition(680.f, 310.f);
 
    disks.push_back(disk11);
    disks.push_back(disk21);
    disks.push_back(disk31);
    disks.push_back(disk12);
    disks.push_back(disk22);
    disks.push_back(disk32);
    disks.push_back(disk13);
    disks.push_back(disk23);
    disks.push_back(disk33);
    disks.push_back(disk14);
    disks.push_back(disk24);
    disks.push_back(disk34);
    disks.push_back(disk15);
    disks.push_back(disk25);
    disks.push_back(disk35);
    disks.push_back(disk16);
    disks.push_back(disk26);
    disks.push_back(disk36);
    disks.push_back(disk17);
    disks.push_back(disk27);
    disks.push_back(disk37);
    disks.push_back(disk18);
    disks.push_back(disk28);
    disks.push_back(disk38);

    for (int i = 0; i < 24; i++) {
        disks[i].setOutlineThickness(-2.f);
        disks[i].setOutlineColor(sf::Color::White);
        if (i % 3 != 0) {
            disks[i].setFillColor(sf::Color::Transparent);
        }
        disks[0].setFillColor(sf::Color::Blue);
        disks[3].setFillColor(sf::Color::Green);
        disks[6].setFillColor(sf::Color::Red);
        disks[9].setFillColor(sf::Color::Cyan);
        disks[12].setFillColor(sf::Color::Yellow);
        disks[15].setFillColor(sf::Color::Magenta);
        disks[18].setFillColor(sf::Color::Black);
        disks[21].setFillColor(sf::Color::Black);
    }

    window.clear(sf::Color::Black);
    window.draw(sig);
    window.draw(input);
    window.draw(Header);
    window.display();


    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                window.close();
            }


            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Num2)
                {
                    window.clear(sf::Color::Black);
                    DrawHeader(window, Header, sig, MoveCount);
                    DrawTower(window, disks, rods, 2);
                    window.display();
                    sf::sleep(sf::seconds(0.5));
                    tower(window, 2, 2,  rods, Header, sig, MoveCount, 3, 2, 1);
                    sf::sleep(sf::seconds(1.5));
                    movecnt = 0;
                }
                if (event.key.code == sf::Keyboard::Num3)
                {
                    window.clear(sf::Color::Black);
                    DrawHeader(window, Header, sig, MoveCount);
                    DrawTower(window, disks, rods, 3);
                    window.display();
                    sf::sleep(sf::seconds(0.5));
                    tower(window, 3, 3, rods, Header, sig, MoveCount, 3, 2, 1);
                    sf::sleep(sf::seconds(1.5));
                    movecnt = 0;
                }
                if (event.key.code == sf::Keyboard::Num4)
                {
                    window.clear(sf::Color::Black);
                    DrawHeader(window, Header, sig, MoveCount);
                    DrawTower(window, disks, rods, 4);
                    window.display();
                    sf::sleep(sf::seconds(0.5));
                    tower(window, 4, 4,  rods, Header, sig, MoveCount, 3, 2, 1);
                    sf::sleep(sf::seconds(1.5));
                    movecnt = 0;
                }
                if (event.key.code == sf::Keyboard::Num5)
                {
                    window.clear(sf::Color::Black);
                    DrawHeader(window, Header, sig, MoveCount);
                    DrawTower(window, disks, rods, 5);
                    window.display();
                    sf::sleep(sf::seconds(0.5));
                    tower(window, 5, 5,  rods, Header, sig, MoveCount, 3, 2, 1);
                    sf::sleep(sf::seconds(1.5));
                    movecnt = 0;
                }
                if (event.key.code == sf::Keyboard::Num6)
                {
                    window.clear(sf::Color::Black);
                    DrawHeader(window, Header, sig, MoveCount);
                    DrawTower(window, disks, rods, 6);
                    window.display();
                    sf::sleep(sf::seconds(0.5));
                    tower(window, 6, 6, rods, Header, sig, MoveCount, 3, 2, 1);
                    sf::sleep(sf::seconds(1.5));
                    movecnt = 0;
                }
                if (event.key.code == sf::Keyboard::Num7)
                {
                    window.clear(sf::Color::Black);
                    DrawHeader(window, Header, sig, MoveCount);
                    DrawTower(window, disks, rods, 7);
                    window.display();
                    sf::sleep(sf::seconds(0.5));
                    tower(window, 7, 7,  rods, Header, sig, MoveCount, 3, 2, 1);
                    sf::sleep(sf::seconds(1.5));
                    movecnt = 0;
                }
                if (event.key.code == sf::Keyboard::Num8)
                {
                    window.clear(sf::Color::Black);
                    DrawHeader(window, Header, sig, MoveCount);
                    DrawTower(window, disks, rods, 8);
                    window.display();
                    sf::sleep(sf::seconds(0.5));
                    tower(window, 8, 8, rods, Header, sig, MoveCount, 3, 2, 1);
                    sf::sleep(sf::seconds(1.5));
                    movecnt = 0;
                }
                if (event.key.code == sf::Keyboard::Enter) {

                    for (int i = 0; i < 24; i++) {
                        disks[i].setOutlineThickness(-2.f);
                        disks[i].setOutlineColor(sf::Color::White);
                        if (i % 3 != 0) {
                            disks[i].setFillColor(sf::Color::Transparent);
                        }
                        disks[0].setFillColor(sf::Color::Blue);
                        disks[3].setFillColor(sf::Color::Green);
                        disks[6].setFillColor(sf::Color::Red);
                        disks[9].setFillColor(sf::Color::Cyan);
                        disks[12].setFillColor(sf::Color::Yellow);
                        disks[15].setFillColor(sf::Color::Magenta);
                        disks[18].setFillColor(sf::Color::Black);
                        disks[21].setFillColor(sf::Color::Black);
                    }

                    window.clear(sf::Color::Black);
                    window.draw(sig);
                    window.draw(input);
                    window.draw(Header);
                    window.display();
                }
            }
        } 
    }
 
    return 0;
}
