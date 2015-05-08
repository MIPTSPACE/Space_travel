# Space_Rangers


Цель проекта:

 	- Моделирование полета корабля с Земли на другую планету Солнечной системы, реализовать расчет возможных орбит и расходов на полёт по каждой орбите для подбора оптимальной техники, визуализацию полета



Общая идея задачи:
	
	- SpaceRangers - бесплатный космический симулятор, который позволит Вам исследовать Солнечную систему  в двух измерениях и составить маршрут межпланетного путешествия(начиная с родной планеты и заканчивая любой другой планетой солнечной системы); посмотреть основные энциклопедические данные о планетах; выбрать корабль для полета и посмотреть основные затраты на полет (топливо, время и т.д.)



Возможности:

	● Расчет оптимальной траектории для полета корабля из одной планеты к другой.
	● Представлены основные типы космических объектов: солнце, планеты.
	● Автопилот типа "выбрал и лети": достаточно кликнуть по объекту мышкой и 
	  нажать 'G', чтобы автоматически перелететь к нему.
	● Автоматическая привязка наблюдателя к движущемуся объекту и автоматический
	  выбор оптимальной скорости полёта.
	● Поиск объектов по имени, масштабируемая карта Вселенной,карта планетной 
	  системы , журнал автопилота.
	● Встроенная энциклопедия с описаниями планеты (описание характеристик-- 
	  перегелий. афелий, эксцентриситет орбиты,физические характеристики). 
	● Движения планет по орбитам просчитываются в реальном времени, возможно 
          ускорение, замедление и инверсия течения времени.
	● Отображение орбит планет, векторов скорости и вращения, меток, координатной 
          сетки, указателя выбранного объекта, вектора текущей скорости.
	● Световые эффекты: короны, солнечные затмения, тени от колец, освещение 
          планетарных тел друг другом.
	● Оригинальная фоновая музыка с контекстным переключением треков.
	● Возможность выбора типа топлива для ракеты
	● Строковый командный анализатор.



Подзадачи: 

	В поставленной задаче можно выделить несколько взаимосвязанных подзадач, а именно:
		●физика солнечной системы
		● физика летательных аппаратов
		● расчет параметров возможных траекторий 
		● расчет расходов топлива, времени
		● вывод информации о расходах для полета
		● работа с данными (сохранение отчета  о полете, возможность просмотреть полет. сохраненный раньше)
		● командный анализатор 
		● визуализация. 



Детальное описание содержания подзадач	:

	1)Физика солнечной системы
		Моделирование движения планет.
		Моделирование освещения тел солнцем.
		Используя исходные данные, программа визуализирует модель Солнечной системы,
                включая орбиту выбранного объекта. Для управления анимацией предусмотрено
		соответствующее меню.Оно предусматривает следующие манипуляции со временем
		воспроизведения: 
			--ускорение и замедление 
			--полная остановка 
			--перемотка на интересующую дату
			--пошаговый режим просмотра
		В пользователя есть возможность посмотреть характеристики каждой планеты
			список --->https://github.com/MIPTSPACE/Space_travel/tree/master/Program_Data/Planets/%D0%A1haracteristics
		
	2)Физика летательных аппаратов
		Моделирование  летательных аппаратов:
			Возможность просмотра основных характеристик(Удельного импульса двигателей, типа топлива, массы полезного(доставляемого на планету) груза)
			Функция расчета топлива в зависимости от движения
				Постановка задачи и принятые упрощения
					Виртуально разгонять ракету в вакууме вдали от планет мне показалось неинтересным. Поэтому задачей будет стартовать с Земли. Будет производится оценка и учет потерь на этапе полета в поле тяжести Земли.
				Входные параметры:
					 В качестве входных данных были выбраны следующие параметры:	
						●Удельный импульс двигателей
						●Коэффициент k, показывающий какое количество топлива приходится на единицу массы конструкции, либо тип топлива (со стандартными значениями k)
						●Масса полезного груза (который необходимо доставить на планету)
						●Количество ступеней на разных этапах полета
				Не учитывающиеся параметры: 	
					Для упрощения задачи не учитываются:
						●Непостоянность тяги двигателей
						●Потери на управление
						●Считается, что k = const, т.е. не учитываются тонкости стоения ракеты - масса креплений, защитной термоповерхности и т.д.
						●Счтается, что каждую ступень используют только на одном из описанных этапов полета, а если на один этап приходится несколько ступеней, то они используются для приращения скорости на равные количества
				Физики и математики(описание процесса):
				
				
				
	3)Расчет параметров полета и расходов
		- возможных дат запуска ракеты для полета по гомановской траектории
		- необходимого количества топлива
		- возможности достижения поставленной задачи с данной ракетой
		- расходов топлива на каждом этапе и вместе
		- массы каждой из ступеней ракеты
		
		Полет выполняется в несколько этапов (помимо движения с выключенными двигателями):
			1. выход на круговую геоцентрическую орбиту
			2. переход переходную орбиту, позволяющую покинуть сферу действия Земли с необходимой для выхода на гелиоцентрическую элиптическую орбиту скоростью, 
			3. коррекция орбиты на (условной) границе сферы действия Земли
			4. Вход в сферу действия планеты и коррекция
			5. Посадка
		На 3 этапе происходит взаимодействие с другой частью проекта - определяется неточность в расчете параметров орбиты, связанная с влиянием планет при движении корабля вокруг Солнца (в первом прибл. - по элипсу), элиптичностью орбит планет и т.д. Далее оценивается необходимая поправка, чтобы достичь сферу действия планеты. Потом производится проверка. При необходимости производится повтор коректировки начальной скорости. 
	4)Вывод отчета о полете
		Вывод следующих данных:
			- возможен ли полет, или необходимо внести изменения (например, необходимо больше ступеней); при этом не выводятся остальные данный и предлагается внести коррективы
			- время полета
			- масса ракеты
			- массы ступеней для каждого из этапов полета
			- масса топлива в целом
			- масса конструкции ступеней (без топлива)
		Программа сохраняет данные о полете и рисует необходимую информацию
			-- график зависимости скорости движения от времени
			-- график зависимости расстояния между планетой и кораблем от времени
			-- график траектории
	5) Командный анализатор
		Удобная командная строка для осуществления всех необходимых движений
		+++возможность добавления своих команд.
	6)Визуализация 
 		Создание макета планет и солнечной системой, работа с окошками и оформления дизайна программы.
		Представление графиков и зависимостей.


		



Состав работ и исполнители:

		1) физика солнечной системы(Волошенюк Сергей)
		2) физика летательных аппаратов (Ливинюк Виктор)
		3) расчет возможных траекторий (Ливинюк Виктор)
		4) расчет параметров полета и расходов(Ливинюк Виктор)
		5) более точный расчет временных расходов на полет (Волошенюк Сергей)
		6) вывод информации о расходах полета (Волошенюк Сергей)
		7) работа с данными (Волошенюк Сергей, Калачева Дарья)
		8) командный анализатор  (Волошенюк Сергей)
		9)визуализация (Калачева Дарья)
Сроки:
		6.04 Работа с данными
		13.04 Физика солнечной системы (финальная версия)
		17,04 командный анализатор
		20,04 Физика литательных апаратов
		20.04 Расчет возможных траекторий, поиск оптимального решения
		21.04 визуализация+ вывод информации о расходах полета
		22.04 - срок показа альфа продуктов.
		06.05 - срок почти полной готовности

Системные требования:
		Os Linux

нужно ботать!



