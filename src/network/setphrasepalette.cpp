#include <QtGui>
#include "setphrasepalette.h"
#include "orosetphrasechat.h"
#include "cyberoroconnection.h"

/* There's also the possibility of eventually using this on other services
 * however unlikely. Should probably have a parent for it but there isn't
 * one easily accessible and hopefully it doesn't matter.*/

SetPhrasePalette::SetPhrasePalette(CyberOroConnection * con) : 
QDialog(0, Qt::Tool | Qt::WindowStaysOnTopHint | Qt::WindowShadeButtonHint), connection(con)
{
	std::map<unsigned short, QString>::iterator it;
	
	for(it = ORO_setphrase.begin(); it != ORO_setphrase.end(); it++)
		actions.push_back(new QAction(it->second, this));
	
	std::vector<QAction *>::iterator actions_it = actions.begin();
	
	button0 = new QPushButton("0");
	QMenu *menu0 = new QMenu(this);
	menu0->addAction(*actions_it); actions_it++;
	menu0->addAction(*actions_it); actions_it++;
	menu0->addAction(*actions_it); actions_it++;
	menu0->addAction(*actions_it); actions_it++;
	menu0->addAction(*actions_it); actions_it++;
	button0->setMenu(menu0);
	
	button1 = new QPushButton("1");
	QMenu *menu1 = new QMenu(this);
	menu1->addAction(*actions_it); actions_it++;
	menu1->addAction(*actions_it); actions_it++;
	menu1->addAction(*actions_it); actions_it++;
	menu1->addAction(*actions_it); actions_it++;
	menu1->addAction(*actions_it); actions_it++;
	button1->setMenu(menu1);
	
	button2 = new QPushButton("2");
	QMenu *menu2 = new QMenu(this);
	menu2->addAction(*actions_it); actions_it++;
	menu2->addAction(*actions_it); actions_it++;
	menu2->addAction(*actions_it); actions_it++;
	menu2->addAction(*actions_it); actions_it++;
	menu2->addAction(*actions_it); actions_it++;
	button2->setMenu(menu2);
	
	button3 = new QPushButton("3");
	QMenu *menu3 = new QMenu(this);
	menu3->addAction(*actions_it); actions_it++;
	menu3->addAction(*actions_it); actions_it++;
	menu3->addAction(*actions_it); actions_it++;
	menu3->addAction(*actions_it); actions_it++;
	menu3->addAction(*actions_it); actions_it++;
	button3->setMenu(menu3);
	
	button4 = new QPushButton("4");
	QMenu *menu4 = new QMenu(this);
	menu4->addAction(*actions_it); actions_it++;
	menu4->addAction(*actions_it); actions_it++;
	menu4->addAction(*actions_it); actions_it++;
	menu4->addAction(*actions_it); actions_it++;
	menu4->addAction(*actions_it); actions_it++;
	button4->setMenu(menu4);
	
	button5 = new QPushButton("5");
	QMenu *menu5 = new QMenu(this);
	menu5->addAction(*actions_it); actions_it++;
	menu5->addAction(*actions_it); actions_it++;
	menu5->addAction(*actions_it); actions_it++;
	menu5->addAction(*actions_it); actions_it++;
	menu5->addAction(*actions_it); actions_it++;
	button5->setMenu(menu5);
	
	button6 = new QPushButton("6");
	QMenu *menu6 = new QMenu(this);
	menu6->addAction(*actions_it); actions_it++;
	menu6->addAction(*actions_it); actions_it++;
	menu6->addAction(*actions_it); actions_it++;
	menu6->addAction(*actions_it); actions_it++;
	menu6->addAction(*actions_it); actions_it++;
	button6->setMenu(menu6);
	
	button7 = new QPushButton("7");
	QMenu *menu7 = new QMenu(this);
	menu7->addAction(*actions_it); actions_it++;
	menu7->addAction(*actions_it); actions_it++;
	menu7->addAction(*actions_it); actions_it++;
	menu7->addAction(*actions_it); actions_it++;
	menu7->addAction(*actions_it); actions_it++;
	button7->setMenu(menu7);
	
	button8 = new QPushButton("8");
	QMenu *menu8 = new QMenu(this);
	menu8->addAction(*actions_it); actions_it++;
	menu8->addAction(*actions_it); actions_it++;
	menu8->addAction(*actions_it); actions_it++;
	menu8->addAction(*actions_it); actions_it++;
	menu8->addAction(*actions_it); actions_it++;
	button8->setMenu(menu8);
	
	button9 = new QPushButton("9");
	QMenu *menu9 = new QMenu(this);
	menu9->addAction(*actions_it); actions_it++;
	menu9->addAction(*actions_it); actions_it++;
	menu9->addAction(*actions_it); actions_it++;
	menu9->addAction(*actions_it); actions_it++;
	menu9->addAction(*actions_it); //actions_it++;
	button9->setMenu(menu9);
	
	
	buttonBox = new QDialogButtonBox(Qt::Horizontal);
	buttonBox->addButton(button0, QDialogButtonBox::ActionRole);
	buttonBox->addButton(button1, QDialogButtonBox::ActionRole);
	buttonBox->addButton(button2, QDialogButtonBox::ActionRole);
	buttonBox->addButton(button3, QDialogButtonBox::ActionRole);
	buttonBox->addButton(button4, QDialogButtonBox::ActionRole);
	buttonBox->addButton(button5, QDialogButtonBox::ActionRole);
	buttonBox->addButton(button6, QDialogButtonBox::ActionRole);
	buttonBox->addButton(button7, QDialogButtonBox::ActionRole);
	buttonBox->addButton(button8, QDialogButtonBox::ActionRole);
	buttonBox->addButton(button9, QDialogButtonBox::ActionRole);

	connect(menu0, SIGNAL(triggered(QAction *)), this, SLOT(slot_triggered(QAction *)));
	connect(menu1, SIGNAL(triggered(QAction *)), this, SLOT(slot_triggered(QAction *)));
	connect(menu2, SIGNAL(triggered(QAction *)), this, SLOT(slot_triggered(QAction *)));
	connect(menu3, SIGNAL(triggered(QAction *)), this, SLOT(slot_triggered(QAction *)));
	connect(menu4, SIGNAL(triggered(QAction *)), this, SLOT(slot_triggered(QAction *)));
	connect(menu5, SIGNAL(triggered(QAction *)), this, SLOT(slot_triggered(QAction *)));
	connect(menu6, SIGNAL(triggered(QAction *)), this, SLOT(slot_triggered(QAction *)));
	connect(menu7, SIGNAL(triggered(QAction *)), this, SLOT(slot_triggered(QAction *)));
	connect(menu8, SIGNAL(triggered(QAction *)), this, SLOT(slot_triggered(QAction *)));
	connect(menu9, SIGNAL(triggered(QAction *)), this, SLOT(slot_triggered(QAction *)));
	
	QGridLayout * mainLayout = new QGridLayout;
	mainLayout->setSizeConstraint(QLayout::SetFixedSize);
	mainLayout->addWidget(buttonBox, 1, 0);
	setLayout(mainLayout);
	
	// or no title?
	//setWindowTitle(tr("Set Phrases"));
	
	//really this should take into account a parent window
	//screen size, something, and this should be hideable, minimizable,
	//something, smaller buttons... FIXME
	move(60, 680);
}

SetPhrasePalette::~SetPhrasePalette()
{
	delete button0;
	delete button1;
	delete button2;
	delete button3;
	delete button4;
	delete button5;
	delete button6;
	delete button7;
	delete button8;
	delete button9;
	delete buttonBox;
	
	std::vector<QAction *>::iterator it;
	for(it = actions.begin(); it != actions.end(); it++)
		delete (*it);
}

void SetPhrasePalette::slot_triggered(QAction * a)
{
	int i = 0;
	std::vector<QAction *>::iterator it;
	std::map<unsigned short, QString>::iterator string_it = ORO_setphrase.begin();
	for(it = actions.begin(); it != actions.end(); it++, i++)
	{
		if(*it == a)
		{
			while(i--)
				string_it++;
			connection->sendSetChatMsg(string_it->first);
			return;
		}
	}
	qDebug("Can't find set phrase for action!");
}
