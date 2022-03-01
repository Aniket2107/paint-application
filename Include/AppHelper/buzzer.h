#ifndef _BUZZER_H_
#define _BUZZER_H_

/** Configuration structure to initialize buzzer    */
typedef struct
{
    PFGpioPortPin buzzerPin;
}BuzzerCfg;

typedef BuzzerCfg* pBuzzerCfg;

/**
 * \brief This function is used to initialize buzzer
 *
 * \param config pointer to buzzer configuration structure to initialize buzzer
 * \return returns status of buzzer initialization
 */
PFEnStatus buzzerOpen(pBuzzerCfg config);

/**
 * \brief This function is used to start the buzzer
 */
void buzzerON(void);

/**
 * \brief This function is used to stop the buzzer
 */
void buzzerOFF(void);

#endif
