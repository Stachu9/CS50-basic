-- Keep a log of any SQL queries you execute as you solve the mystery.
-- Read crime scene reports:
SELECT description FROM crime_scene_reports WHERE year = 2021 AND month = 7 AND day = 28 AND street = "Humphrey Street";
-- Read witnesses interviews:
SELECT name, transcript FROM interviews WHERE year = 2021 AND month = 7 AND day = 28 AND transcript LIKE "%bakery%";
-- Check Legget Street ATM transaction before robbery
SELECT account_number, amount FROM atm_transactions WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = "Leggett Street" AND transaction_type = "withdraw";
-- Check person id, who withdrawed money from ATM
SELECT person_id FROM bank_accounts JOIN (SELECT account_number, amount FROM atm_transactions WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = "Leggett Street" AND transaction_type = "withdraw") AS x ON bank_accounts.account_number = x.account_number;
-- !!Check names, phone numbers, passports, lcense plates, account creation year who withdrawed money from ATM
SELECT name, phone_number, passport_number, license_plate FROM people JOIN (SELECT person_id, creation_year, amount FROM bank_accounts JOIN (SELECT account_number, amount FROM atm_transactions WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = "Leggett Street" AND transaction_type = "withdraw") AS x ON bank_accounts.account_number = x.account_number) AS z ON people.id = z.person_id;
-- !!Check logs from bakery parking
SELECT license_plate FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute <= 25 AND minute >= 15 AND activity = "exit";
-- !!Check phone calls
SELECT caller, receiver FROM phone_calls WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60;
-- Checkk Fiftyville airport id
SELECT id FROM airports WHERE full_name LIKE "%iftyville%";
-- Check first flight from fiftyville on 29.07
SELECT id, destination_airport_id, hour, minute FROM flights WHERE origin_airport_id = (SELECT id FROM airports WHERE full_name LIKE "%iftyville%") AND year = 2021 AND month = 7 AND day = 29 ORDER BY hour, minute LIMIT 1;
-- !!!!!Check destination airport
Select city FROM airports WHERE id = (SELECT destination_airport_id FROM flights WHERE origin_airport_id = (SELECT id FROM airports WHERE full_name LIKE "%iftyville%") AND year = 2021 AND month = 7 AND day = 29 ORDER BY hour, minute LIMIT 1);
-- !!Check passangers on flight
SELECT passport_number, seat FROM passengers WHERE flight_id = (SELECT id FROM flights WHERE origin_airport_id = (SELECT id FROM airports WHERE full_name LIKE "%iftyville%") AND year = 2021 AND month = 7 AND day = 29 ORDER BY hour, minute LIMIT 1);
-- join ATM person with parking EXIT
SELECT name, phone_number, passport_number FROM
    (SELECT name, phone_number, passport_number, license_plate FROM people JOIN
        (SELECT person_id, creation_year, amount FROM bank_accounts JOIN
            (SELECT account_number, amount FROM atm_transactions WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = "Leggett Street" AND transaction_type = "withdraw")
        AS x ON bank_accounts.account_number = x.account_number)
    AS z ON people.id = z.person_id) AS j JOIN
    (SELECT license_plate FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute <= 25 AND minute >= 15 AND activity = "exit")
AS y ON j.license_plate = y.license_plate;
-- Join tables
SELECT name, phone_number FROM (SELECT name, phone_number, passport_number FROM
    (SELECT name, phone_number, passport_number, license_plate FROM people JOIN
        (SELECT person_id, creation_year, amount FROM bank_accounts JOIN
            (SELECT account_number, amount FROM atm_transactions WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = "Leggett Street" AND transaction_type = "withdraw")
        AS x ON bank_accounts.account_number = x.account_number)
    AS z ON people.id = z.person_id) AS j JOIN
    (SELECT license_plate FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute <= 25 AND minute >= 15 AND activity = "exit")
AS y ON j.license_plate = y.license_plate) AS a
JOIN (SELECT passport_number, seat FROM passengers WHERE flight_id = (SELECT id FROM flights WHERE origin_airport_id = (SELECT id FROM airports WHERE full_name LIKE "%iftyville%") AND year = 2021 AND month = 7 AND day = 29 ORDER BY hour, minute LIMIT 1)) AS b ON a.passport_number = b.passport_number;
-- Find robber
SELECT name FROM (SELECT name, phone_number FROM (SELECT name, phone_number, passport_number FROM
    (SELECT name, phone_number, passport_number, license_plate FROM people JOIN
        (SELECT person_id, creation_year, amount FROM bank_accounts JOIN
            (SELECT account_number, amount FROM atm_transactions WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = "Leggett Street" AND transaction_type = "withdraw")
        AS x ON bank_accounts.account_number = x.account_number)
    AS z ON people.id = z.person_id) AS j JOIN
    (SELECT license_plate FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute <= 25 AND minute >= 15 AND activity = "exit")
AS y ON j.license_plate = y.license_plate) AS a
JOIN (SELECT passport_number, seat FROM passengers WHERE flight_id = (SELECT id FROM flights WHERE origin_airport_id = (SELECT id FROM airports WHERE full_name LIKE "%iftyville%") AND year = 2021 AND month = 7 AND day = 29 ORDER BY hour, minute LIMIT 1)) AS b ON a.passport_number = b.passport_number) AS c JOIN (SELECT caller, receiver FROM phone_calls WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60) AS d ON c.phone_number = d.caller;
-- find accomplice
SELECT name FROM people WHERE phone_number = (SELECT receiver FROM (SELECT name, phone_number FROM (SELECT name, phone_number, passport_number FROM
    (SELECT name, phone_number, passport_number, license_plate FROM people JOIN
        (SELECT person_id, creation_year, amount FROM bank_accounts JOIN
            (SELECT account_number, amount FROM atm_transactions WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = "Leggett Street" AND transaction_type = "withdraw")
        AS x ON bank_accounts.account_number = x.account_number)
    AS z ON people.id = z.person_id) AS j JOIN
    (SELECT license_plate FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute <= 25 AND minute >= 15 AND activity = "exit")
AS y ON j.license_plate = y.license_plate) AS a
JOIN (SELECT passport_number, seat FROM passengers WHERE flight_id = (SELECT id FROM flights WHERE origin_airport_id = (SELECT id FROM airports WHERE full_name LIKE "%iftyville%") AND year = 2021 AND month = 7 AND day = 29 ORDER BY hour, minute LIMIT 1)) AS b ON a.passport_number = b.passport_number) AS c JOIN (SELECT caller, receiver FROM phone_calls WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60) AS d ON c.phone_number = d.caller);