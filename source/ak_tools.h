/* ----------------------------------------------------------------------------------------------- */
/*   Copyright (c) 2014 - 2017 by Axel Kenzo, axelkenzo@mail.ru                                    */
/*   All rights reserved.                                                                          */
/*                                                                                                 */
/*  Разрешается повторное распространение и использование как в виде исходного кода, так и         */
/*  в двоичной форме, с изменениями или без, при соблюдении следующих условий:                     */
/*                                                                                                 */
/*   1. При повторном распространении исходного кода должно оставаться указанное выше уведомление  */
/*      об авторском праве, этот список условий и последующий отказ от гарантий.                   */
/*   2. При повторном распространении двоичного кода должна сохраняться указанная выше информация  */
/*      об авторском праве, этот список условий и последующий отказ от гарантий в документации     */
/*      и/или в других материалах, поставляемых при распространении.                               */
/*   3. Ни имя владельца авторских прав, ни имена его соратников не могут быть использованы в      */
/*      качестве рекламы или средства продвижения продуктов, основанных на этом ПО без             */
/*      предварительного письменного разрешения.                                                   */
/*                                                                                                 */
/*  ЭТА ПРОГРАММА ПРЕДОСТАВЛЕНА ВЛАДЕЛЬЦАМИ АВТОРСКИХ ПРАВ И/ИЛИ ДРУГИМИ СТОРОНАМИ "КАК ОНА ЕСТЬ"  */
/*  БЕЗ КАКОГО-ЛИБО ВИДА ГАРАНТИЙ, ВЫРАЖЕННЫХ ЯВНО ИЛИ ПОДРАЗУМЕВАЕМЫХ, ВКЛЮЧАЯ, НО НЕ             */
/*  ОГРАНИЧИВАЯСЬ ИМИ, ПОДРАЗУМЕВАЕМЫЕ ГАРАНТИИ КОММЕРЧЕСКОЙ ЦЕННОСТИ И ПРИГОДНОСТИ ДЛЯ КОНКРЕТНОЙ */
/*  ЦЕЛИ. НИ В КОЕМ СЛУЧАЕ НИ ОДИН ВЛАДЕЛЕЦ АВТОРСКИХ ПРАВ И НИ ОДНО ДРУГОЕ ЛИЦО, КОТОРОЕ МОЖЕТ    */
/*  ИЗМЕНЯТЬ И/ИЛИ ПОВТОРНО РАСПРОСТРАНЯТЬ ПРОГРАММУ, КАК БЫЛО СКАЗАНО ВЫШЕ, НЕ НЕСЁТ              */
/*  ОТВЕТСТВЕННОСТИ, ВКЛЮЧАЯ ЛЮБЫЕ ОБЩИЕ, СЛУЧАЙНЫЕ, СПЕЦИАЛЬНЫЕ ИЛИ ПОСЛЕДОВАВШИЕ УБЫТКИ,         */
/*  ВСЛЕДСТВИЕ ИСПОЛЬЗОВАНИЯ ИЛИ НЕВОЗМОЖНОСТИ ИСПОЛЬЗОВАНИЯ ПРОГРАММЫ (ВКЛЮЧАЯ, НО НЕ             */
/*  ОГРАНИЧИВАЯСЬ ПОТЕРЕЙ ДАННЫХ, ИЛИ ДАННЫМИ, СТАВШИМИ НЕПРАВИЛЬНЫМИ, ИЛИ ПОТЕРЯМИ ПРИНЕСЕННЫМИ   */
/*  ИЗ-ЗА ВАС ИЛИ ТРЕТЬИХ ЛИЦ, ИЛИ ОТКАЗОМ ПРОГРАММЫ РАБОТАТЬ СОВМЕСТНО С ДРУГИМИ ПРОГРАММАМИ),    */
/*  ДАЖЕ ЕСЛИ ТАКОЙ ВЛАДЕЛЕЦ ИЛИ ДРУГОЕ ЛИЦО БЫЛИ ИЗВЕЩЕНЫ О ВОЗМОЖНОСТИ ТАКИХ УБЫТКОВ.            */
/*                                                                                                 */
/*   ak_tools.h                                                                                    */
/* ----------------------------------------------------------------------------------------------- */
/*   Файл содержит описания служебных функций и переменных, не экспортруемых за пределы библиотеки */
/* ----------------------------------------------------------------------------------------------- */
 #ifndef    __AK_TOOLS_H__
 #define    __AK_TOOLS_H__

/* ----------------------------------------------------------------------------------------------- */
 #include <libakrypt.h>
 #include <SecretKeyData.h>

/* ----------------------------------------------------------------------------------------------- */
/*! \brief Неэкспортируемая функция установления уровня аудита. */
 int ak_log_set_level( int );

/*! \brief Функция устанавливает значение опции с заданным именем. */
 int ak_libakrypt_set_option( const char *name, const int value );
/*! \brief Функция возвращает значение опции с заданным именем. */
 int ak_libakrypt_get_option( const char *name );

/* ----------------------------------------------------------------------------------------------- */
/*! \brief Функция выделяет память для указателя OCTET_STRING_t и копирует в нее данные, хранящиеся в ptr. */
 int ak_ptr_to_asn1_octet_string( const ak_pointer , const size_t , OCTET_STRING_t * );
/*! \brief Сохранение asn1 структуры в файле в der-представлении. */
 int ak_asn1_save_to_der_file( struct asn_TYPE_descriptor_s *, void *, const char * );
/*! \brief Чтение asn1 структуры в der-представлении из заданного файла. */
 int ak_asn1_load_from_der_file( struct asn_TYPE_descriptor_s *, void *, const char * );
/*! \brief Преобразование asn1 идентификатора объекта в строку. */
 int ak_static_str_from_object_identifier( char * , size_t , const OBJECT_IDENTIFIER_t * );

 #endif
/* ----------------------------------------------------------------------------------------------- */
/*                                                                                 ak_libakrypt.h  */
/* ----------------------------------------------------------------------------------------------- */
