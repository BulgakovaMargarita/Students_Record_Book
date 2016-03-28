#ifndef CORE_H
#define CORE_H


class CoreAPI
{

public:
    CoreAPI();
    /**
    * @brief считывание данных из файла
    */
    virtual void scan()=0;
    /**
    * @brief вывод оценок ученика на экран или запись в файл
    */
    virtual void show_marks()=0;
    /**
    * @brief поиск и подсчет количества отличников
    */
    virtual void find_excelllent_pupil()=0;
    /**
    * @brief поиск и подсчет количества хорошистов
    */
    virtual void find_good_pupil()=0;
    /**
     * @brief поиск и подсчет количества отстающих учеников
     */
    virtual void find_lagging_pupil()=0;
    /**
     * @brief подсчет успеваемости класса
     */
    virtual void performance_calculation()=0;
    /**
    * @brief изменение оценки ученика
    */
    virtual void change_mark()=0;
   

};

#endif // CORE_H
