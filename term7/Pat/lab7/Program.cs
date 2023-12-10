AudioPlayer player = new AudioPlayer();

string? input = null;
while (input != string.Empty)
{
    Console.WriteLine("w - play\ns - stop\nd - next song\na - previous song");
    input = Console.ReadLine();
    switch (input)
    {
        case "w" : player.Play(); break;
        case "s" : player.Stop(); break;
        case "d" : player.Next(); break;
        case "a" : player.Previous(); break;
        default: break;
    };
}

interface IState
{
    void Play();
    void Stop();
    void Next();
    void Previous();
}

class AudioPlayer
{
    private IState state;

    public AudioPlayer() => state = new StoppedState(this);

    public void ChangeState(IState newState) => state = newState;

    public void Play() => state.Play();

    public void Stop() => state.Stop();

    public void Next() => state.Next();

    public void Previous() => state.Previous();
}

class StoppedState : IState
{
    private AudioPlayer player;

    public StoppedState(AudioPlayer player) => this.player = player;

    public void Play()
    {
        Console.WriteLine("Playing audio");
        player.ChangeState(new PlayingState(player));
    }

    public void Stop() => Console.WriteLine("Audio is already stopped");

    public void Next() => Console.WriteLine("Cannot play next track, audio is stopped");

    public void Previous() => Console.WriteLine("Cannot play previous track, audio is stopped");
}

class PlayingState : IState
{
    private AudioPlayer player;

    public PlayingState(AudioPlayer player) => this.player = player;

    public void Play() => Console.WriteLine("Audio is already playing");

    public void Stop()
    {
        Console.WriteLine("Stopping audio");
        player.ChangeState(new StoppedState(player));
    }

    public void Next() => Console.WriteLine("Playing next track");

    public void Previous() => Console.WriteLine("Playing previous track");
}

/*
 * | Текущее состояние | Входное событие| Следующее состояние| Действия
 * | ----------------- | -------------- | ------------------ | ---------------------
 * | StoppedState      | Play           | PlayingState       | Воспроизведение аудио
 * | StoppedState      | Stop           | StoppedState       | Остановка аудио
 * | StoppedState      | Next           | StoppedState       | Невозможно перейти
 * | StoppedState      | Previous       | StoppedState       | Невозможно перейти
 * | PlayingState      | Play           | PlayingState       | Воспроизведение аудио
 * | PlayingState      | Stop           | StoppedState       | Остановка аудио
 * | PlayingState      | Next           | PlayingState       | Воспроизведение следующего трека
 * | PlayingState      | Previous       | PlayingState       | Воспроизведение предыдущего трека
 */