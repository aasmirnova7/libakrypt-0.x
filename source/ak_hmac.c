/* ----------------------------------------------------------------------------------------------- */
/*  Copyright (c) 2014 - 2017 by Axel Kenzo, axelkenzo@mail.ru                                     */
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
/*   ak_hmac.c                                                                                     */
/* ----------------------------------------------------------------------------------------------- */
 #include <ak_hmac.h>
 #include <ak_tools.h>
 #include <ak_context_manager.h>

/* ----------------------------------------------------------------------------------------------- */
/*! @param hctx контекст алгоритма hmac.
    @return В случае успеха функция возвращает ноль (\ref ak_error_ok). В случае возникновения
    ошибки возвращается ее код.                                                                    */
/* ----------------------------------------------------------------------------------------------- */
 int ak_hmac_key_create_streebog256( ak_hmac_key hctx )
{
 int error = ak_error_ok;

  /* инициализируем контекст функции хеширования */
   if(( error = ak_hash_create_streebog256( &hctx->ctx )) != ak_error_ok )
     return ak_error_message( error, __func__, "invalid creation of hash function context");

  /* инициализируем контекст секретного ключа */
   if(( error = ak_skey_create( &hctx->key, hctx->ctx.bsize, 8 )) != ak_error_ok ) {
     ak_hash_destroy( &hctx->ctx );
     return ak_error_message( error, __func__, "wrong creation of secret key" );
   }

  /* доопределяем поля секретного ключа */
   if(( hctx->key.oid = ak_handle_get_context(
                        ak_oid_find_by_name( "hmac-streebog256" ), oid_engine )) == NULL ) {
     error = ak_error_get_value();
     ak_hash_destroy( &hctx->ctx );
     ak_skey_destroy( &hctx->key );
     return ak_error_message( error, __func__, "internal OID search error");
   }

  /* устанавливаем ресурс ключа */
   hctx->key.resource.counter = ak_libakrypt_get_hmac_key_counter_resource();

  /* hctx->key.data не изменяется */
  /* также мы используем методы секретного ключа, установленные по-умолчанию */
 return ak_error_ok;
}

/* ----------------------------------------------------------------------------------------------- */
/*! @param hctx контекст алгоритма hmac.
    @return В случае успеха функция возвращает ноль (\ref ak_error_ok). В случае возникновения
    ошибки возвращается ее код.                                                                    */
/* ----------------------------------------------------------------------------------------------- */
 int ak_hmac_key_create_streebog512( ak_hmac_key hctx )
{
 int error = ak_error_ok;

  /* инициализируем контекст функции хеширования */
   if(( error = ak_hash_create_streebog512( &hctx->ctx )) != ak_error_ok )
     return ak_error_message( error, __func__, "invalid creation of hash function context");

  /* инициализируем контекст секретного ключа */
   if(( error = ak_skey_create( &hctx->key, hctx->ctx.bsize, 8 )) != ak_error_ok ) {
     ak_hash_destroy( &hctx->ctx );
     return ak_error_message( error, __func__, "wrong creation of secret key" );
   }

  /* доопределяем поля секретного ключа */
   if(( hctx->key.oid = ak_handle_get_context(
                        ak_oid_find_by_name( "hmac-streebog512" ), oid_engine )) == NULL ) {
     error = ak_error_get_value();
     ak_hash_destroy( &hctx->ctx );
     ak_skey_destroy( &hctx->key );
     return ak_error_message( error, __func__, "internal OID search error");
   }

  /* устанавливаем ресурс ключа */
   hctx->key.resource.counter = ak_libakrypt_get_hmac_key_counter_resource();

  /* hctx->key.data не изменяется */
  /* также мы используем методы секретного ключа, установленные по-умолчанию */
 return ak_error_ok;
}

/* ----------------------------------------------------------------------------------------------- */
/*! @param hctx контекст алгоритма hmac.
    @param handle дескриптор таблиц замен алгоритма хеширования ГОСТ Р 34.11-94
    @return В случае успеха функция возвращает ноль (\ref ak_error_ok). В случае возникновения
    ошибки возвращается ее код.                                                                    */
/* ----------------------------------------------------------------------------------------------- */
 int ak_hmac_key_create_gosthash94( ak_hmac_key hctx, ak_handle handle )
{
 int error = ak_error_ok;

  /* инициализируем контекст функции хеширования */
   if(( error = ak_hash_create_gosthash94( &hctx->ctx, handle )) != ak_error_ok )
     return ak_error_message( error, __func__, "invalid creation of hash function context");

  /* инициализируем контекст секретного ключа */
   if(( error = ak_skey_create( &hctx->key, hctx->ctx.bsize, 8 )) != ak_error_ok ) {
     ak_hash_destroy( &hctx->ctx );
     return ak_error_message( error, __func__, "wrong creation of secret key" );
   }

  /* доопределяем поля секретного ключа */
   if(( hctx->key.oid = ak_handle_get_context(
                        ak_oid_find_by_name( "hmac-gosthash94" ), oid_engine )) == NULL ) {
     error = ak_error_get_value();
     ak_hash_destroy( &hctx->ctx );
     ak_skey_destroy( &hctx->key );
     return ak_error_message( error, __func__, "internal OID search error");
   }

  /* устанавливаем ресурс ключа */
   hctx->key.resource.counter = ak_libakrypt_get_hmac_key_counter_resource();

  /* hctx->key.data не изменяется */
  /* также мы используем методы секретного ключа, установленные по-умолчанию */
 return ak_error_ok;
}

/* ----------------------------------------------------------------------------------------------- */
/*! @param hctx контекст ключа алгоритма hmac
    @return В случае успеха возвращается ноль (\ref ak_error_ok). В противном случае возвращается
    код ошибки.                                                                                    */
/* ----------------------------------------------------------------------------------------------- */
 int ak_hmac_key_destroy( ak_hmac_key hctx )
{
  int error = ak_error_ok;
  if( hctx == NULL ) return ak_error_message( ak_error_null_pointer, __func__ ,
                                                 "destroying a null pointer to hmac key context" );
  if(( error = ak_skey_destroy( &hctx->key )) != ak_error_ok )
    ak_error_message( error, __func__ , "incorrect destroying secret key of hmac" );
  if(( error = ak_hash_destroy( &hctx->ctx )) != ak_error_ok )
    ak_error_message( error, __func__ , "incorrect destroying hash function context of hmac" );

 return error;
}

/* ----------------------------------------------------------------------------------------------- */
/*! @param hctx контекст ключа алгоритма hmac
    @return Функция возвращает NULL. В случае возникновения ошибки, ее код может быть получен с
    помощью вызова функции ak_error_get_value().                                                   */
/* ----------------------------------------------------------------------------------------------- */
 ak_pointer ak_hmac_key_delete( ak_pointer hctx )
{
  if( hctx != NULL ) {
      ak_hmac_key_destroy(( ak_hmac_key ) hctx );
      free( hctx );
     } else ak_error_message( ak_error_null_pointer, __func__ ,
                                                       "using null pointer to hmac key context" );
 return NULL;
}

/* ----------------------------------------------------------------------------------------------- */
/*                                                                                      ak_hmac.c  */
/* ----------------------------------------------------------------------------------------------- */
