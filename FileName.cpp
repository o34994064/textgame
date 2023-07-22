#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <random>

using namespace std;

// 角色类
class Character {
public:
    string name;
    int level;      // 等级
    int levelexp; // 经验
    int stamina;    // 耐力
    int strength;   // 力量
    int agility;    // 敏捷
    int intellect;  // 智力
    int maxHealth;  // 最大生命值
    int maxMana;    // 最大魔法值
    int attack;     // 攻击力
    int defense;    // 防御力
    vector<string> skills;  // 技能列表

    // 构造函数
    Character(string charName, int charStamina, int charStrength, int charAgility, int charIntellect)
        : name(charName), stamina(charStamina), strength(charStrength), agility(charAgility), intellect(charIntellect) {
        level = 1;
        levelexp = level * 100;
        maxHealth = stamina * 10;
        maxMana = intellect * 10;
        attack = strength * 2;
        defense = agility * 2;

    }

    // 显示属性面板
    void showAttributes() {
        cout << "=============================" << endl;
        cout << "角色属性面板：" << endl;
        cout << "名称：" << name << endl;
        cout << "等级：" << level << endl;
        cout << "经验值：" << "0/"<<levelexp << endl;
        cout << "-----------------------------" << endl;
        cout << "耐力：" << stamina << endl;
        cout << "力量：" << strength << endl;
        cout << "敏捷：" << agility << endl;
        cout << "智力：" << intellect << endl;
        cout << "-----------------------------" << endl;
        cout << "生命值：" << maxHealth << endl;
        cout << "魔力值：" << maxMana << endl;
        cout << "攻击力：" << attack << endl;
        cout << "防御力：" << defense << endl;
    }

    // 获得经验值
    void gainExperience(int experience) {
        // 处理经验值逻辑
        if（experience>=levelexp）{level++；experience_
    -=levelexp；}
    }

    // 显示技能列表
    void showSkills() {
        cout << "技能列表：" << endl;
        if (skills.empty()) {
            cout << "无可用技能。" << endl;
        }
        else {
            for (int i = 0; i < skills.size(); ++i) {
                cout << "[" << i << "] " << skills[i] << endl;
            }
        }
    }

    // 使用技能
    void useSkill(int skillIndex) {
        if (skillIndex >= 0 && skillIndex < skills.size()) {
            string skillName = skills[skillIndex];
            cout << name << "使用了技能 " << skillName << "！" << endl;

            // 根据技能名字执行相应的效果
            if (skillName == "火球术" and maxMana >= 10) {
                int damage = intellect * 3;
                maxMana = maxMana - 10;
                cout << skillName << "对怪物造成了 " << damage << " 点火焰伤害！" << endl;
                cout << skillName << "消耗魔力值10 ," << " 当前魔力值：" << maxMana << endl;
            }
            else if (skillName == "冰冻术") {
                int damage = intellect * 4;
                cout << skillName << "对怪物造成了 " << damage << " 点冰冻伤害！" << endl;
                cout << skillName << "消耗魔力值10 ," << " 当前魔力值：" << maxMana << endl;
            }
            else if (skillName == "闪电链") {
                int damage = intellect * 5;
                cout << skillName << "对怪物造成了 " << damage << " 点闪电伤害！" << endl;
                cout << skillName << "消耗魔力值10 ," << " 当前魔力值：" << maxMana << endl;
            }
            else if (skillName == "治疗术") {
                int healAmount = intellect * 5;
                cout << skillName << "为自己恢复了 " << healAmount << " 点生命值！" << endl;
                cout << skillName << "消耗魔力值10 ," << " 当前魔力值：" << maxMana << endl;
            }
            else {
                cout << skillName << "魔力值不足！ " << " 当前魔力值：" << maxMana << endl;
            }
        }
        else {
            cout << "无效的选择。" << endl;
        }
    }
};

// 装备类
class Equipment {
public:
    string name;
    int type;     // 装备类型: 1 - 武器，2 - 护甲，3 - 饰品
    int bonus;    // 基础属性加成
    int specialBonus;    // 极品属性加成，根据装备类型加成不同

    // 构造函数
    Equipment(string equipName, int equipType, int equipBonus, int equipSpecialBonus)
        : name(equipName), type(equipType), bonus(equipBonus), specialBonus(equipSpecialBonus) {}

    // 生成随机的极品属性
    void generateSpecialBonus() {
        if (type == 1) {  // 武器
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_real_distribution<double> dis(0.0, 1.0);

            // 以一定的概率生成极品属性
            if (dis(gen) < 0.2) {
                // 生成3%力量加成
                specialBonus = 3;
            }
            else {
                specialBonus = 0;
            }
        }
        else if (type == 2) {  // 护甲
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_real_distribution<double> dis(0.0, 1.0);

            // 以一定的概率生成极品属性
            if (dis(gen) < 0.2) {
                // 生成5点耐力加成
                specialBonus = 5;
            }
            else {
                specialBonus = 0;
            }
        }
        else if (type == 3) {  // 饰品
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_real_distribution<double> dis(0.0, 1.0);

            // 以一定的概率生成极品属性
            if (dis(gen) < 0.2) {
                // 生成2%每次战斗后回血属性
                specialBonus = 2;
            }
            else {
                specialBonus = 0;
            }
        }
    }
};

// 怪物类
class Monster {
public:
    string name;
    int maxHealth;  // 最大生命值
    int attack;     // 攻击力
    int defense;    // 防御力

    // 构造函数
    Monster(string monName, int monMaxHealth, int monAttack, int monDefense)
        : name(monName), maxHealth(monMaxHealth), attack(monAttack), defense(monDefense) {}

    // 显示怪物属性
    void showAttributes() {
        cout << "=============================" << endl;
        cout << "怪物属性：" << endl;
        cout << "名称：" << name << endl;
        cout << "生命值：" << maxHealth << endl;
        cout << "攻击力：" << attack << endl;
        cout << "防御力：" << defense << endl;
        cout << "=============================" << endl;
    }
};

// 游戏类
class Game {
public:
    Character* player;
    vector<Equipment*> inventory;
    vector<Monster*> monsters;
    int currentLevel;
    int bossLevel;
    vector<string> skillList;  // 技能列表

public:
    Game(string playerName) {
        player = new Character(playerName, 10, 5, 5, 5);
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

    // 初始化怪物
    void initializeMonsters() {
        monsters.push_back(new Monster("小怪1", 30, 8, 2));
        monsters.push_back(new Monster("小怪2", 35, 10, 3));
        monsters.push_back(new Monster("小怪3", 40, 12, 4));
        monsters.push_back(new Monster("小怪4", 45, 14, 5));
        monsters.push_back(new Monster("BOSS怪物", 100, 20, 10));
    }

    // 初始化技能列表
    void initializeSkills() {
        skillList.push_back("火球术");
        skillList.push_back("冰冻术");
        skillList.push_back("闪电链");
        skillList.push_back("治疗术");
    }

    // 清空怪物列表
    void clearMonsters() {
        for (auto monster : monsters) {
            delete monster;
        }
        monsters.clear();
    }

    // 清空背包
    void clearInventory() {
        for (auto item : inventory) {
            delete item;
        }
        inventory.clear();
    }

    // 战斗
    void battle() {
        Monster* currentMonster = getRandomMonster();
        cout << "遭遇了 " << currentMonster->name << "！" << endl;

        while (player->maxHealth > 0 && currentMonster->maxHealth > 0) {
            // 玩家回合
            playerTurn(currentMonster);

            // 检查怪物是否死亡
            if (currentMonster->maxHealth <= 0) {
                break;
            }

            // 怪物回合
            monsterTurn(currentMonster);
        }

        if (player->maxHealth <= 0) {
            cout << "你被击败了！游戏结束。" << endl;
        }
        else {
            cout << "你战胜了 " << currentMonster->name << "！获得胜利！" << endl;
            // 获得经验值
            int experience = currentMonster->maxHealth / 2;
            player->gainExperience(experience);
            player->maxMana += 10;
            if (player->maxMana > player->intellect * 10) { player->maxMana = player->intellect * 10; }
            // 掉落装备
            dropEquipment();
        }

        cout << "=============================" << endl;
    }

    // 玩家回合
    void playerTurn(Monster* currentMonster) {
        cout << "轮到你的回合，请选择操作：" << endl;
        cout << "[1] 普通攻击" << endl;
        cout << "[2] 使用技能" << endl;

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
            cout << "无效的选择。" << endl;
            break;
        }
    }

    // 玩家普通攻击
    void playerAttack(Monster* currentMonster) {
        int playerDamage = player->attack - currentMonster->defense;
        if (playerDamage < 0) {
            playerDamage = 0;
        }
        currentMonster->maxHealth -= playerDamage;
        cout << player->name << "对" << currentMonster->name << "造成了 " << playerDamage << " 点伤害！" << endl;
    }

    // 玩家使用技能
    void playerUseSkill(Monster* currentMonster) {
        player->showSkills();
        cout << "请选择要使用的技能编号：";
        int skillIndex;
        cin >> skillIndex;

        if (skillIndex >= 0 && skillIndex < player->skills.size()) {
            player->useSkill(skillIndex);
        }
        else {
            cout << "无效的选择。" << endl;
        }
    }

    // 怪物回合
    void monsterTurn(Monster* currentMonster) {
        int monsterDamage = currentMonster->attack - player->defense;
        if (monsterDamage < 0) {
            monsterDamage = 0;
        }
        player->maxHealth -= monsterDamage;
        cout << currentMonster->name << "对" << player->name << "造成了 " << monsterDamage << " 点伤害！" << endl;
    }

    // 随机获取一个怪物
    Monster* getRandomMonster() {
        int index = rand() % monsters.size();
        return monsters[index];
    }

    // 掉落装备
    void dropEquipment() {
        int equipType = rand() % 3 + 1;
        int randomBonus = rand() % 5 + 1;

        string equipName;
        int equipBonus;
        int equipSpecialBonus = 0;    // 极品属性加成，根据装备类型加成不同
        switch (equipType) {
        case 1:
            equipName = "武器";
            equipBonus = player->strength + randomBonus;
            break;
        case 2:
            equipName = "护甲";
            equipBonus = player->stamina + randomBonus;
            break;
        case 3:
            equipName = "饰品";
            equipBonus = randomBonus;
            break;
        }
        Equipment* newEquip = new Equipment(equipName, equipType, equipBonus, equipSpecialBonus);
        inventory.push_back(newEquip);
        cout << "你获得了一件装备：" << newEquip->name << "，属性加成：" << newEquip->bonus << endl;
    }

    // 展示背包中的装备
    void showInventory() {
        cout << "背包中的装备：" << endl;
        if (inventory.empty()) {
            cout << "背包为空。" << endl;
        }
        else {
            for (int i = 0; i < inventory.size(); ++i) {
                cout << "[" << i << "] " << inventory[i]->name << " (加成属性：" << inventory[i]->bonus << ")" << endl;
            }
        }
    }

    // 穿戴装备
    void equipFromInventory(int index) {
        if (index >= 0 && index < inventory.size()) {
            Equipment* equip = inventory[index];

            switch (equip->type) {
            case 1:  // 武器
                player->attack += equip->bonus;
                player->strength += equip->bonus / 2;
                break;
            case 2:  // 护甲
                player->defense += equip->bonus;
                player->stamina += equip->bonus / 2;
                break;
            case 3:  // 饰品
                player->maxHealth += player->maxHealth * equip->bonus / 100;
                break;
            }

            cout << "你装备了 " << equip->name << "，属性加成：" << equip->bonus << endl;
            inventory.erase(inventory.begin() + index);
        }
        else {
            cout << "无效的选择。" << endl;
        }
    }

    // 展示可学习的技能列表
    void showSkillList() {
        cout << "可学习的技能列表：" << endl;
        if (skillList.empty()) {
            cout << "无可学习的技能。" << endl;
        }
        else {
            for (int i = 0; i < skillList.size(); ++i) {
                cout << "[" << i << "] " << skillList[i] << endl;
            }
        }
    }

    // 将技能添加到角色的技能列表中
    void addSkillToCharacter(int skillIndex) {
        if (skillIndex >= 0 && skillIndex < skillList.size()) {
            string skillName = skillList[skillIndex];
            player->skills.push_back(skillName);
            cout << player->name << "学习了技能 " << skillName << "！" << endl;
            skillList.erase(skillList.begin() + skillIndex);
        }
        else {
            cout << "无效的选择。" << endl;
        }
    }
};

int main() {
    srand(time(0));  // 随机数种子

    string playerName;
    cout << "欢迎来到角色扮演游戏！" << endl;
    cout << "请输入你的角色名字：";
    cin >> playerName;

    Game game(playerName);

    while (true) {
        cout << "=============================" << endl;
        cout << "请选择操作：" << endl;
        cout << "[1] 开始战斗" << endl;
        cout << "[2] 查看角色属性面板" << endl;
        cout << "[3] 查看背包" << endl;
        cout << "[4] 穿戴装备" << endl;
        cout << "[5] 查看可学习的技能" << endl;
        cout << "[6] 学习技能" << endl;
        cout << "[7] 退出游戏" << endl;

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
            cout << "请选择要穿戴的装备编号：";
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
            cout << "请选择要学习的技能编号：";
            int skillIndex;
            cin >> skillIndex;
            game.addSkillToCharacter(skillIndex);
            break;
        }
        case 7:
            cout << "游戏结束。" << endl;
            return 0;
        default:
            cout << "无效的选择，请重新选择。" << endl;
            break;
        }
    }

    return 0;
}
