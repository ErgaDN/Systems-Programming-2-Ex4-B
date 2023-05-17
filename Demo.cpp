/**
 * Demo file for the exercise on binary tree
 *
 * @author Evgeny Hershkovitch Neiterman
 * @since 2023-03
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
using namespace std;

#include "sources/Team.hpp" //no need for other includes

using namespace ariel;


int main() {
      // Point a(0,3), b(4,3);
      // Point p = Point::moveTowards(a,b,5);
      // cout << "P: " << p.print() << endl;
      
      // double distance = 2.5;
      // double dist = a.distance(b);
      // cout << "A: " << a.print() << endl;
      // cout << "B: " << b.print() << endl << endl;
      

      // double ratio = distance / dist;
      // double dx = b.getX() - a.getX();
      // double dy = b.getY() - a.getY();
      // // x += ratio * dx;
      // // y += ratio * dy;
      // a.setX(a.getX() + ratio * dx);
      // a.setY(a.getY() + ratio * dy);
      // cout << "A: " <<a.print() << endl;
      // cout << "B: " <<b.print() << endl;

      


    Point a(32.3,44),b(1.3,3.5), c(6, 9);
    assert(a.distance(b) == b.distance(a));
    Cowboy *tom = new Cowboy("Tom", a);
    OldNinja *sushi = new OldNinja("sushi", b);
    tom->shoot(sushi);
    cout << tom->print() <<endl;
    // cout << sushi->print() <<endl;

    // sushi->move(tom);
    cout << sushi->print() <<endl;

    Cowboy *ran = new Cowboy("Ran", c);
    // cout << ran->print() <<endl;
    sushi->slash(ran);
    cout << ran->print() <<endl;

    Team team_A(tom); 
    team_A.add(new YoungNinja("Yogi", Point(64,57)));

    // Team bb(tom);// should throw tom is already in team a

     Team team_B(sushi);
     team_B.add(new TrainedNinja("Hikari", Point(12,81)));

    cout << "A ";
    team_A.print();
    cout << "B ";
    team_B.print();
    cout << "Attack!" << endl;
    //  while(team_A.stillAlive() > 0 && team_B.stillAlive() > 0){
        team_A.attack(&team_B);
        // team_B.attack(&team_A);
        // team_A.print();
        // team_B.print();
    //  }
    cout << "A ";
    team_A.print();
    cout << "B ";
    team_B.print();

    //  if (team_A.stillAlive() > 0) cout << "winner is team_A" << endl;
    //  else cout << "winner is team_B" << endl;

     return 0; // no memory issues. Team should free the memory of its members. both a and b teams are on the stack. 

}
