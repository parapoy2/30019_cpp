#include <iostream>
#include <vector>
#include <memory>
#include <string>
using namespace std;

struct Node {
    string data;
    vector<shared_ptr<Node>> children;

    Node(const string& d) : data(d) {}
};

void addChild(shared_ptr<Node> parent, shared_ptr<Node> child) {
    parent->children.push_back(child);
}

void printTree(const shared_ptr<Node>& node, int depth = 0) {
    for (int i = 0; i < depth; ++i) cout << "  ";
    cout << node->data << "\n";
    for (const shared_ptr<Node>& child : node->children) {
        printTree(child, depth + 1);
    }
}

int main() {
    ///дир
    auto director = make_shared<Node>("Director");

    ///асест+заст++дир
    auto asstGrad = make_shared<Node>("Asst. Dir. of Graduate Studies");
    auto assocAcad = make_shared<Node>("Assoc. Dir. for Academic Programs");
    auto adminAsst = make_shared<Node>("Administrative Assistant to the Director");
    auto mainOffice = make_shared<Node>("Main Office Assistant");
    auto assocStudent = make_shared<Node>("Assoc. Dir. for Student Services Administrations");
    auto fellow = make_shared<Node>("Faculty Fellow for Strategic Initiatives");
    auto advisoryBoard = make_shared<Node>("School of Music Advisory Board");

  //відділи
    addChild(director, asstGrad);
    addChild(director, assocAcad);
    addChild(director, adminAsst);
    addChild(director, mainOffice);
    addChild(director, assocStudent);
    addChild(director, fellow);
    addChild(director, advisoryBoard);

    //відділ
    auto popularMusic = make_shared<Node>("Popular Music");
    auto academicStudies = make_shared<Node>("Academic Studies");
    auto performanceStudies = make_shared<Node>("Performance Studies");
    auto staff = make_shared<Node>("Staff");

    addChild(director, popularMusic);
    addChild(director, academicStudies);
    addChild(director, performanceStudies);
    addChild(director, staff);

    //підвідд
    addChild(popularMusic, make_shared<Node>("Audio Engineering"));
    addChild(popularMusic, make_shared<Node>("Music Business"));
    addChild(popularMusic, make_shared<Node>("Performance & Songwriting"));
    addChild(popularMusic, make_shared<Node>("Jazz Studies"));
    addChild(popularMusic, make_shared<Node>("Music + Entertainment"));

    //підв2
    addChild(academicStudies, make_shared<Node>("Musicology"));
    addChild(academicStudies, make_shared<Node>("Music Education"));
    addChild(academicStudies, make_shared<Node>("Music Theory/Composition"));
    addChild(academicStudies, make_shared<Node>("General Studies in Music"));
    addChild(academicStudies, make_shared<Node>("Music Therapy"));

    //підв3
    addChild(performanceStudies, make_shared<Node>("Conducting"));
    addChild(performanceStudies, make_shared<Node>("Athletic Bands"));
    addChild(performanceStudies, make_shared<Node>("Asst. Band Instructor"));
    addChild(performanceStudies, make_shared<Node>("Administrative Associate"));
    addChild(performanceStudies, make_shared<Node>("Staff Pianist"));

    // Staff
    addChild(staff, make_shared<Node>("Business Office Manager"));
    addChild(staff, make_shared<Node>("Operations + Events Manager"));
    addChild(staff, make_shared<Node>("Marketing Communications Officer"));
    addChild(staff, make_shared<Node>("Recruitment + Enrollment Officer"));
    addChild(staff, make_shared<Node>("Technical Director"));
    addChild(staff, make_shared<Node>("Facilities Manager"));

    printTree(director);

    cin.get();
    return 0;
}