#pragma once
class CNetwork
{
public:
	CNetwork();
	~CNetwork();

	static librg_ctx_t ctx;
	static librg_entity_t * local_player;
	static std::vector<CPed*> players;

	static bool client_running;
	static bool client_connected;
	static bool connected;

	static void on_connect_request(librg_event_t *event);
	static void on_connect_accepted(librg_event_t *event);
	static void on_connect_refused(librg_event_t *event);
	static void on_entity_create(librg_event_t * event);
	static void on_entity_update(librg_event_t *event);

	static void ClientConnectThread();
	static void AttemptConnect();
};

