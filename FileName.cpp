#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <random>

using namespace std;

// ��ɫ��
class Character {
public:
    string name;

    int stamina;    // ����
    int strength;   // ����
    int agility;    // ����
    int intellect;    // ����
    int maxHealth;  // �������ֵ
    int maxMana;  // ���ħ��ֵ
    int attack;     // ������
    int defense;    // ������
    vector<string> skills;  // �����б�

    // ���캯��
    Character(string charName, int charStamina, int charStrength, int charAgility, int charIntellect)
        : name(charName), stamina(charStamina), strength(charStrength), agility(charAgility), intellect(charIntellect) {
        maxHealth = stamina * 10;
        maxMana = intellect * 10;
        attack = strength * 2;
        defense = agility * 2;

    }

    // ��ʾ�������
    void showAttributes() {
        cout << "=============================" << endl;
        cout << "��ɫ������壺" << endl;
        cout << "���ƣ�" << name << endl;
        cout << "������" << stamina << endl;
        cout << "������" << strength << endl;
        cout << "���ݣ�" << agility << endl;
        cout << "������" << intellect << endl;
        cout << "-----------------------------" << endl;
        cout << "����ֵ��" << maxHealth << endl;
        cout << "ħ��ֵ��" << maxMana << endl;
        cout << "��������" << attack << endl;
        cout << "��������" << defense << endl;
    }

    // ��þ���ֵ
    void gainExperience(int experience) {
        // ������ֵ�߼�
    }

    // ��ʾ�����б�
    void showSkills() {
        cout << "�����б�" << endl;
        if (skills.empty()) {
            cout << "�޿��ü��ܡ�" << endl;
        }
        else {
            for (int i = 0; i < skills.size(); ++i) {
                cout << "[" << i << "] " << skills[i] << endl;
            }
        }
    }

    // ʹ�ü���
    void useSkill(int skillIndex) {
        if (skillIndex >= 0 && skillIndex < skills.size()) {
            string skillName = skills[skillIndex];
            cout << name << "ʹ���˼��� " << skillName << "��" << endl;

            // ���ݼ�������ִ����Ӧ��Ч��
            if (skillName == "������" and maxMana>=10) {
                int damage = intellect * 3;
                maxMana = maxMana - 10;
                cout << skillName << "�Թ�������� " << damage << " ������˺���" << endl;
                cout << skillName << "����ħ��ֵ10 ," << " ��ǰħ��ֵ��" << maxMana << endl;
            }
            else if (skillName == "������") {
                int damage = intellect * 4;
                cout << skillName << "�Թ�������� " << damage << " ������˺���" << endl;
                cout << skillName << "����ħ��ֵ10 ," << " ��ǰħ��ֵ��" << maxMana << endl;
            }
            else if (skillName == "������") {
                int damage = intellect * 5;
                cout << skillName << "�Թ�������� " << damage << " �������˺���" << endl;
                cout << skillName << "����ħ��ֵ10 ," << " ��ǰħ��ֵ��" << maxMana << endl;
            }
            else if (skillName == "������") {
                int healAmount = intellect * 5;
                cout << skillName << "Ϊ�Լ��ָ��� " << healAmount << " ������ֵ��" << endl;
                cout << skillName << "����ħ��ֵ10 ," << " ��ǰħ��ֵ��" << maxMana << endl;
            }
            else {
            cout << skillName << "ħ��ֵ���㣡 " << " ��ǰħ��ֵ��" << maxMana << endl;
            }
        }
        else {
            cout << "��Ч��ѡ��" << endl;
        }
    }
};

// װ����
class Equipment {
public:
    string name;
    int type;     // װ������: 1 - ������2 - ���ף�3 - ��Ʒ
    int bonus;    // �������Լӳ�
    int specialBonus;    // ��Ʒ���Լӳɣ�����װ�����ͼӳɲ�ͬ

    // ���캯��
    Equipment(string equipName, int equipType, int equipBonus, int equipSpecialBonus)
        : name(equipName), type(equipType), bonus(equipBonus), specialBonus(equipSpecialBonus) {}

    // ��������ļ�Ʒ����
    void generateSpecialBonus() {
        if (type == 1) {  // ����
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_real_distribution<double> dis(0.0, 1.0);

            // ��һ���ĸ������ɼ�Ʒ����
            if (dis(gen) < 0.2) {
                // ����3%�����ӳ�
                specialBonus = 3;
            }
            else {
                specialBonus = 0;
            }
        }
        else if (type == 2) {  // ����
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_real_distribution<double> dis(0.0, 1.0);

            // ��һ���ĸ������ɼ�Ʒ����
            if (dis(gen) < 0.2) {
                // ����5�������ӳ�
                specialBonus = 5;
            }
            else {
                specialBonus = 0;
            }
        }
        else if (type == 3) {  // ��Ʒ
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_real_distribution<double> dis(0.0, 1.0);

            // ��һ���ĸ������ɼ�Ʒ����
            if (dis(gen) < 0.2) {
                // ����2%ÿ��ս�����Ѫ����
                specialBonus = 2;
            }
            else {
                specialBonus = 0;
            }
        }
    }
};

// ������
class Monster {
public:
    string name;
    int maxHealth;  // �������ֵ
    int attack;     // ������
    int defense;    // ������

    // ���캯��
    Monster(string monName, int monMaxHealth, int monAttack, int monDefense)
        : name(monName), maxHealth(monMaxHealth), attack(monAttack), defense(monDefense) {}

    // ��ʾ��������
    void showAttributes() {
        cout << "=============================" << endl;
        cout << "�������ԣ�" << endl;
        cout << "���ƣ�" << name << endl;
        cout << "����ֵ��" << maxHealth << endl;
        cout << "��������" << attack << endl;
        cout << "��������" << defense << endl;
        cout << "=============================" << endl;
    }
};

// ��Ϸ��
class Game {
public:
    Character* player;
    vector<Equipment*> inventory;
    vector<Monster*> monsters;
    int currentLevel;
    int bossLevel;
    vector<string> skillList;  // �����б�

public:
    Game(string playerName) {
        player = new Character(playerName, 10, 5, 5,5);
        currentLevel = 1;
        bossLevel = 5;
        initializeMonsters();
        initializeSkills();
    }

    ~Game() {
        delete player;
        clearInventory();
        clearMonsters();
    }

    // ��ʼ������
    void initializeMonsters() {
        monsters.push_back(new Monster("С��1", 30, 8, 2));
        monsters.push_back(new Monster("С��2", 35, 10, 3));
        monsters.push_back(new Monster("С��3", 40, 12, 4));
        monsters.push_back(new Monster("С��4", 45, 14, 5));
        monsters.push_back(new Monster("BOSS����", 100, 20, 10));
    }

    // ��ʼ�������б�
    void initializeSkills() {
        skillList.push_back("������");
        skillList.push_back("������");
        skillList.push_back("������");
        skillList.push_back("������");
    }

    // ��չ����б�
    void clearMonsters() {
        for (auto monster : monsters) {
            delete monster;
        }
        monsters.clear();
    }

    // ��ձ���
    void clearInventory() {
        for (auto item : inventory) {
            delete item;
        }
        inventory.clear();
    }

    // ս��
    void battle() {
        Monster* currentMonster = getRandomMonster();
        cout << "������ " << currentMonster->name << "��" << endl;

        while (player->maxHealth > 0 && currentMonster->maxHealth > 0) {
            // ��һغ�
            playerTurn(currentMonster);

            // �������Ƿ�����
            if (currentMonster->maxHealth <= 0) {
                break;
            }

            // ����غ�
            monsterTurn(currentMonster);
        }

        if (player->maxHealth <= 0) {
            cout << "�㱻�����ˣ���Ϸ������" << endl;
        }
        else {
            cout << "��սʤ�� " << currentMonster->name << "�����ʤ����" << endl;
            // ��þ���ֵ
            int experience = currentMonster->maxHealth / 2;
            player->gainExperience(experience);
            player->maxMana += 10;
            if (player->maxMana > player->intellect*10) { player->maxMana = player->intellect * 10; }
            // ����װ��
            dropEquipment();
        }

        cout << "=============================" << endl;
    }

    // ��һغ�
    void playerTurn(Monster* currentMonster) {
        cout << "�ֵ���Ļغϣ���ѡ�������" << endl;
        cout << "[1] ��ͨ����" << endl;
        cout << "[2] ʹ�ü���" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            playerAttack(currentMonster);
            break;
        case 2:
            playerUseSkill(currentMonster);
            break;
        default:
            cout << "��Ч��ѡ��" << endl;
            break;
        }
    }

    // �����ͨ����
    void playerAttack(Monster* currentMonster) {
        int playerDamage = player->attack - currentMonster->defense;
        if (playerDamage < 0) {
            playerDamage = 0;
        }
        currentMonster->maxHealth -= playerDamage;
        cout << player->name << "��" << currentMonster->name << "����� " << playerDamage << " ���˺���" << endl;
    }

    // ���ʹ�ü���
    void playerUseSkill(Monster* currentMonster) {
        player->showSkills();
        cout << "��ѡ��Ҫʹ�õļ��ܱ�ţ�";
        int skillIndex;
        cin >> skillIndex;

        if (skillIndex >= 0 && skillIndex < player->skills.size()) {
            player->useSkill(skillIndex);
        }
        else {
            cout << "��Ч��ѡ��" << endl;
        }
    }

    // ����غ�
    void monsterTurn(Monster* currentMonster) {
        int monsterDamage = currentMonster->attack - player->defense;
        if (monsterDamage < 0) {
            monsterDamage = 0;
        }
        player->maxHealth -= monsterDamage;
        cout << currentMonster->name << "��" << player->name << "����� " << monsterDamage << " ���˺���" << endl;
    }

    // �����ȡһ������
    Monster* getRandomMonster() {
        int index = rand() % monsters.size();
        return monsters[index];
    }

    // ����װ��
    void dropEquipment() {
        int equipType = rand() % 3 + 1;
        int randomBonus = rand() % 5 + 1;

        string equipName;
        int equipBonus;
        int equipSpecialBonus = 0;    // ��Ʒ���Լӳɣ�����װ�����ͼӳɲ�ͬ
        switch (equipType) {
        case 1:
            equipName = "����";
            equipBonus = player->strength + randomBonus;
            break;
        case 2:
            equipName = "����";
            equipBonus = player->stamina + randomBonus;
            break;
        case 3:
            equipName = "��Ʒ";
            equipBonus = randomBonus;
            break;
        }
        Equipment* newEquip = new Equipment(equipName, equipType, equipBonus, equipSpecialBonus);
        inventory.push_back(newEquip);
        cout << "������һ��װ����" << newEquip->name << "�����Լӳɣ�" << newEquip->bonus << endl;
    }

    // չʾ�����е�װ��
    void showInventory() {
        cout << "�����е�װ����" << endl;
        if (inventory.empty()) {
            cout << "����Ϊ�ա�" << endl;
        }
        else {
            for (int i = 0; i < inventory.size(); ++i) {
                cout << "[" << i << "] " << inventory[i]->name << " (�ӳ����ԣ�" << inventory[i]->bonus << ")" << endl;
            }
        }
    }

    // ����װ��
    void equipFromInventory(int index) {
        if (index >= 0 && index < inventory.size()) {
            Equipment* equip = inventory[index];

            switch (equip->type) {
            case 1:  // ����
                player->attack += equip->bonus;
                player->strength += equip->bonus / 2;
                break;
            case 2:  // ����
                player->defense += equip->bonus;
                player->stamina += equip->bonus / 2;
                break;
            case 3:  // ��Ʒ
                player->maxHealth += player->maxHealth * equip->bonus / 100;
                break;
            }

            cout << "��װ���� " << equip->name << "�����Լӳɣ�" << equip->bonus << endl;
            inventory.erase(inventory.begin() + index);
        }
        else {
            cout << "��Ч��ѡ��" << endl;
        }
    }

    // չʾ��ѧϰ�ļ����б�
    void showSkillList() {
        cout << "��ѧϰ�ļ����б�" << endl;
        if (skillList.empty()) {
            cout << "�޿�ѧϰ�ļ��ܡ�" << endl;
        }
        else {
            for (int i = 0; i < skillList.size(); ++i) {
                cout << "[" << i << "] " << skillList[i] << endl;
            }
        }
    }

    // ��������ӵ���ɫ�ļ����б���
    void addSkillToCharacter(int skillIndex) {
        if (skillIndex >= 0 && skillIndex < skillList.size()) {
            string skillName = skillList[skillIndex];
            player->skills.push_back(skillName);
            cout << player->name << "ѧϰ�˼��� " << skillName << "��" << endl;
            skillList.erase(skillList.begin() + skillIndex);
        }
        else {
            cout << "��Ч��ѡ��" << endl;
        }
    }
};

int main() {
    srand(time(0));  // ���������

    string playerName;
    cout << "��ӭ������ɫ������Ϸ��" << endl;
    cout << "��������Ľ�ɫ���֣�";
    cin >> playerName;

    Game game(playerName);

    while (true) {
        cout << "=============================" << endl;
        cout << "��ѡ�������" << endl;
        cout << "[1] ��ʼս��" << endl;
        cout << "[2] �鿴��ɫ�������" << endl;
        cout << "[3] �鿴����" << endl;
        cout << "[4] ����װ��" << endl;
        cout << "[5] �鿴��ѧϰ�ļ���" << endl;
        cout << "[6] ѧϰ����" << endl;
        cout << "[7] �˳���Ϸ" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            game.battle();
            break;
        case 2:
            game.player->showAttributes();
            break;
        case 3:
            game.showInventory();
            break;
        case 4: {
            game.showInventory();
            cout << "��ѡ��Ҫ������װ����ţ�";
            int equipIndex;
            cin >> equipIndex;
            game.equipFromInventory(equipIndex);
            break;
        }
        case 5:
            game.showSkillList();
            break;
        case 6: {
            game.showSkillList();
            cout << "��ѡ��Ҫѧϰ�ļ��ܱ�ţ�";
            int skillIndex;
            cin >> skillIndex;
            game.addSkillToCharacter(skillIndex);
            break;
        }
        case 7:
            cout << "��Ϸ������" << endl;
            return 0;
        default:
            cout << "��Ч��ѡ��������ѡ��" << endl;
            break;
        }
    }

    return 0;
}