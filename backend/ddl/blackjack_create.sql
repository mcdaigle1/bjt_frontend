CREATE DATABASE blackjack;

CREATE USER 'blackjack'@'localhost' IDENTIFIED BY 'blackjack';

GRANT ALL ON *.* TO 'blackjack'@'localhost';

CREATE TABLE IF NOT EXISTS player (
    id              INT             NOT NULL PRIMARY KEY AUTO_INCREMENT,
    create_time     TIMESTAMP       NOT NULL DEFAULT CURRENT_TIMESTAMP,
    mod_time        TIMESTAMP       NOT NULL DEFAULT 0,
    email           VARCHAR(256)    NOT NULL UNIQUE,
    status          INT             NOT NULL,
    validation_id   VARCHAR(256)    NOT NULL,
    password_salt   VARCHAR(256)    NOT NULL,
    password_md5    VARCHAR(128)    NOT NULL
); 

INSERT INTO player (create_time, mod_time, email, status, validation_id, password_salt, password_md5)
VALUES (now(), now(), 'mcdaigle1@gmail.com', 0, '1234', 'blackjack', '4fb5584245edbb40aa67eed4ebc42fac');

CREATE TABLE IF NOT EXISTS player_strategy (
    id              INT             NOT NULL PRIMARY KEY AUTO_INCREMENT,
    create_time     TIMESTAMP       NOT NULL DEFAULT CURRENT_TIMESTAMP,
    mod_time        TIMESTAMP       NOT NULL DEFAULT 0,
    name            VARCHAR(256)    NOT NULL,
    description     VARCHAR(256),
    status          INT             NOT NULL,
    player_id       INT             NOT NULL,
    strategy_md5    INT             NOT NULL,
    strategy_set    VARCHAR(1024)   NOT NULL
); 

INSERT INTO player_strategy (create_time, mod_time, name, description, status, player_id, strategy_md5, strategy_set)
VALUES (now(), now(), 'Default', 'Default player strategy', 0, 0, 'b28be804ea966a3c86ca1034eeaf41ec',
'[[1,1,1,1,1,1,1,1,1,1],[1,1,1,1,1,1,1,1,1,1],[1,1,1,1,1,1,1,1,1,1],[1,1,1,1,1,1,1,1,1,1],[1,3,3,3,3,1,1,1,1,1],[3,3,3,3,3,3,3,3,1,1],[3,3,3,3,3,3,3,3,3,1],[1,1,2,2,2,1,1,1,1,1],[2,2,2,2,2,1,1,1,1,1],[2,2,2,2,2,1,1,1,1,1],[2,2,2,2,2,1,1,1,1,1],[2,2,2,2,2,1,1,1,1,1],[2,2,2,2,2,2,2,2,2,2],[2,2,2,2,2,2,2,2,2,2],[2,2,2,2,2,2,2,2,2,2],[2,2,2,2,2,2,2,2,2,2],[1,1,1,3,3,1,1,1,1,1],[1,1,1,3,3,1,1,1,1,1],[1,1,3,3,3,1,1,1,1,1],[1,1,3,3,3,1,1,1,1,1],[1,3,3,3,3,1,1,1,1,1],[2,3,3,3,3,2,2,1,1,1],[2,2,2,2,2,2,2,2,2,2],[2,2,2,2,2,2,2,2,2,2],[2,2,2,2,2,2,2,2,2,2],[4,4,4,4,4,4,4,4,4,4],[4,4,4,4,4,4,1,1,1,1],[4,4,4,4,4,4,1,1,1,1],[1,1,1,4,4,1,1,1,1,1],[3,3,3,3,3,3,3,3,1,1],[4,4,4,4,4,1,1,1,1,1],[4,4,4,4,4,4,1,1,1,1],[4,4,4,4,4,4,4,4,4,4],[4,4,4,4,4,2,4,4,2,2],[2,2,2,2,2,2,2,2,2,2]]');

CREATE TABLE IF NOT EXISTS dealer_strategy (
    id              INT             NOT NULL PRIMARY KEY AUTO_INCREMENT,
    create_time     TIMESTAMP       NOT NULL DEFAULT CURRENT_TIMESTAMP,
    mod_time        TIMESTAMP       NOT NULL DEFAULT 0,
    name            VARCHAR(256)    NOT NULL,
    description     VARCHAR(1024),
    status          INT             NOT NULL,
    player_id       INT             NOT NULL,
    strategy_md5    INT             NOT NULL UNIQUE,
    strategy_set    VARCHAR(1024)   NOT NULL
); 

INSERT INTO dealer_strategy (create_time, mod_time, name, description, status, player_id, strategy_md5, strategy_set)
VALUES (now(), now(), 'Default', 'Default dealer strategy', 0, 0, '4cdce559f4be8accf84ff9349260faf6',
'[1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,1,1,1,1,1,2,2,2,2,2]');

CREATE TABLE IF NOT EXISTS game (
    id                     INT             NOT NULL PRIMARY KEY AUTO_INCREMENT,
    create_time            TIMESTAMP       NOT NULL DEFAULT CURRENT_TIMESTAMP,
    mod_time               TIMESTAMP       NOT NULL DEFAULT 0,
    name                   VARCHAR(256)    NOT NULL,
    description            VARCHAR(1024),
    status                 INT             NOT NULL,
    player_id              INT             NOT NULL,
    num_decks              INT             NOT NULL,
    hand_limit             INT             NOT NULL,
    bankroll               INT             NOT NULL,
    end_at_zero            BOOL            NOT NULL,
    player_strategy_id     INT             NOT NULL,
    dealer_strategy_id     INT             NOT NULL,
    bet_strategy_id        INT             NOT NULL,
    reserve_id             INT
);

INSERT INTO game (create_time, mod_time, name, description, status, num_decks, hand_limit, 
	bankroll, end_at_zero, player_strategy_id, dealer_strategy_id, bet_strategy_id, reserve_id)
values (now(), now(), 'Default Game', 'This is the default game', 0, 6, 100, 1000, 0, 1, 1, 1, null);

CREATE TABLE IF NOT EXISTS shoe (
    id              INT             NOT NULL PRIMARY KEY AUTO_INCREMENT,
    create_time     TIMESTAMP       NOT NULL,
    mod_time        TIMESTAMP       NOT NULL,
    description     VARCHAR(256),
    num_decks       INT             NOT NULL,
    game_id         INT             NOT NULL,
    sequence        INT             NOT NULL,
    cards           TEXT            NOT NULL,
    cut_position    VARCHAR(16)     NOT NULL
);

CREATE TABLE IF NOT EXISTS player_hand (
    id              INT             NOT NULL PRIMARY KEY AUTO_INCREMENT,
    create_time     TIMESTAMP       NOT NULL,
    mod_time        TIMESTAMP       NOT NULL,
    description     VARCHAR(256),
    player_id       INT             NOT NULL,
    game_id         INT             NOT NULL,
    shoe_id         INT             NOT NULL,
    sequence        INT             NOT NULL,
    sub_sequence    INT,
    parent_sequence INT,
    bet             INT             NOT NULL,
    bankroll        INT             NOT NULL,
    card_list       TEXT            NOT NULL,
    outcome         INT             NOT NULL
);

CREATE TABLE IF NOT EXISTS dealer_hand (
    id              INT             NOT NULL PRIMARY KEY AUTO_INCREMENT,
    create_time     TIMESTAMP       NOT NULL,
    mod_time        TIMESTAMP       NOT NULL,
    description     VARCHAR(256),
    game_id         INT             NOT NULL,
    shoe_id         INT             NOT NULL,
    sequence        INT             NOT NULL,
    card_list       TEXT            NOT NULL
);

CREATE TABLE IF NOT EXISTS bet_strategy (
    id              INT             NOT NULL PRIMARY KEY AUTO_INCREMENT,
    create_time     TIMESTAMP       NOT NULL,
    mod_time        TIMESTAMP       NOT NULL,
    name            VARCHAR(256)    NOT NULL,
    description     VARCHAR(1024),
    status          INT             NOT NULL,
    player_id       INT             NOT NULL,
    strategy_json   VARCHAR(2048)   NOT NULL
);

