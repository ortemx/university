str = "МЕЕЕСНЬМТПЦСНРЧЯТЫЗДОЕЕТОЫЕТИСООВЧЛИГЧСЕСИВКИЕОИЕКЛВСАУОНСЕЛОЬЯПНМБИТСОЙНЗОИЕЕЕНФВДОАЛЕНСМО"
str = "шифрсиспользованиемперестановки"
str = "ШФССОЬОАИМЕЕТНВИИРИПЛЗВНЕПРСАОК"
ladder_len: int = 2
for i in range(2, len(str)):
    for j in range(0, len(str)):
        t = t % len(str)
        print()
    
    
"""
91:

0 45 90 135-->
ШФССОЬОАИМЕЕТНВИ
ИРИПЛЗВНЕПРСАОК
2
МЕЕЕСНЬМТПЦСНРЧЯТЫЗДОЕЕТОЫЕТИСООВЧЛИГЧСЕСИВКИЕ
ОИЕКЛВСАУОНСЕЛОЬЯПНМБИТСОЙНЗОИЕЕЕНФВДОАЛЕНСМО
3
МЕЕЕСНЬМТПЦСНРЧЯТЫЗДОЕЕТОЫЕТИСО
ОВЧЛИГЧСЕСИВКИЕОИЕКЛВСАУОНСЕЛОЬ
ЯПНМБИТСОЙНЗОИЕЕЕНФВДОАЛЕНСМО
4
МЕЕЕСНЬМТПЦСНРЧЯТЫЗДОЕЕ
ТОЫЕТИСООВЧЛИГЧСЕСИВКИЕ
ОИЕКЛВСАУОНСЕЛОЬЯПНМБИТ
СОЙНЗОИЕЕЕНФВДОАЛЕНСМО
5
МЕЕЕСНЬМТПЦСНРЧЯТЫЗ
ДОЕЕТОЫЕТИСООВЧЛИГЧ
СЕСИВКИЕОИЕКЛВСАУОН
СЕЛОЬЯПНМБИТСОЙНЗОИ
ЕЕЕНФВДОАЛЕНСМО
6
МЕЕЕСНЬМТПЦСНРЧЯ
ТЫЗДОЕЕТОЫЕТИСОО
ВЧЛИГЧСЕСИВКИЕОИ
ЕКЛВСАУОНСЕЛОЬЯП
НМБИТСОЙНЗОИЕЕЕН
ФВДОАЛЕНСМО
7
МЕЕЕСНЬМТПЦСН
РЧЯТЫЗДОЕЕТОЫ
ЕТИСООВЧЛИГЧС
ЕСИВКИЕОИЕКЛВ
САУОНСЕЛОЬЯПН
МБИТСОЙНЗОИЕЕ
ЕНФВДОАЛЕНСМО
8
МЕЕЕСНЬМТПЦС
НРЧЯТЫЗДОЕЕТ
ОЫЕТИСООВЧЛИ
ГЧСЕСИВКИЕОИ
ЕКЛВСАУОНСЕЛ
ОЬЯПНМБИТСОЙ
НЗОИЕЕЕНФВДО
АЛЕНСМО
9
МЕЕЕСНЬМТПЦ
СНРЧЯТЫЗДОЕ
ЕТОЫЕТИСООВ
ЧЛИГЧСЕСИВК
ИЕОИЕКЛВСАУ
ОНСЕЛОЬЯПНМ
БИТСОЙНЗОИЕ
ЕЕНФВДОАЛЕН
СМО
10
МЕЕЕСНЬМТП
ЦСНРЧЯТЫЗД
ОЕЕТОЫЕТИС
ООВЧЛИГЧСЕ
СИВКИЕОИЕК
ЛВСАУОНСЕЛ
ОЬЯПНМБИТС
ОЙНЗОИЕЕЕН
ФВДОАЛЕНСМ
О
11
МЕЕЕСНЬМТ
ПЦСНРЧЯТЫ
ЗДОЕЕТОЫЕ
ТИСООВЧЛИ
ГЧСЕСИВКИ
ЕОИЕКЛВСА
УОНСЕЛОЬЯ
ПНМБИТСОЙ
НЗОИЕЕЕНФ
ВДОАЛЕНСМ
О
12
МЕЕЕСНЬМ
ТПЦСНРЧЯ
ТЫЗДОЕЕТ
ОЫЕТИСОО
ВЧЛИГЧСЕ
СИВКИЕОИ
ЕКЛВСАУО
НСЕЛОЬЯП
НМБИТСОЙ
НЗОИЕЕЕН
ФВДОАЛЕН
СМО

13
МЕЕЕСНЬ
МТПЦСНР
ЧЯТЫЗДО
ЕЕТОЫЕТ
ИСООВЧЛ
ИГЧСЕСИ
ВКИЕОИЕ
КЛВСАУО
НСЕЛОЬЯ
ПНМБИТС
ОЙНЗОИЕ
ЕЕНФВДО
АЛЕНСМО

14
МЕЕЕСН
ЬМТПЦСНРЧЯТЫЗДОЕЕТОЫЕТИСООВЧЛИГЧСЕСИВКИЕОИЕКЛВСАУОНСЕЛОЬЯПНМБИТСОЙНЗОИЕЕЕНФВДОАЛЕНСМО

15
МЕЕЕС
НЬМТПЦСНРЧЯТЫЗДОЕЕТОЫЕТИСООВЧЛИГЧСЕСИВКИЕОИЕКЛВСАУОНСЕЛОЬЯПНМБИТСОЙНЗОИЕЕЕНФВДОАЛЕНСМО

16
МЕЕЕ
СНЬМ
ТПЦС
НРЧЯ
ТЫЗДОЕЕТОЫЕТИСООВЧЛИГЧСЕСИВКИЕОИЕКЛВСАУОНСЕЛОЬЯПНМБИТСОЙНЗОИЕЕЕНФВДОАЛЕНСМО


17
МЕЕ
ЕСН
ЬМТ
ПЦСНРЧЯТЫЗДОЕЕТОЫЕТИСООВЧЛИГЧСЕСИВКИЕОИЕКЛВСАУОНСЕЛОЬЯПНМБИТСОЙНЗОИЕЕЕНФВДОАЛЕНСМО

МЕ
ЕЕ
СН
ЬМ
ТП
ЦС
НР
ЧЯ
ТЫ
ЗД
ОЕ
ЕТ
ОЫ
ЕТ
ИС
ОО
ВЧ
ЛИ
ГЧ
СЕ
СИВКИЕОИЕКЛВСАУОНСЕЛОЬЯПНМБИТСОЙНЗОИЕЕЕНФВДОАЛЕНСМО

ВЩИТЗЬВЬЛОНЕНИУШИЗЕГАЕТСЮЕНОЙОСВЕПТПЫВЗШТРРОБОПАЕАОМНЛОЛОТМРЯЯЕЬЛОЛЕНА

ЕОИЕ
КЛВ

САУОНСЕЛОЬЯПНМБИТСОЙ
НЗОИЕЕЕНФВДОАЛЕНСМО

САУОНСЕЛОЬЯПН
МБИТСОЙНЗОИЕЕ
ЕНФВДОАЛЕНСМО

САУОНСЕЛОЬ
ЯПНМБИТСОЙ
НЗОИЕЕЕНФВ
ДОАЛЕНСМО

САУОНСЕЛО
ЬЯПНМБИТС
ОЙНЗОИЕЕЕ
НФВДОАЛЕН
СМО

САУОНСЕ
ЛОЬЯПНМ
БИТСОЙН
ЗОИЕЕЕН
ФВДОАЛЕ
НСМО
"""    