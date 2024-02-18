from pytube import YouTube


url = input("Linki gir: ")
my_video = YouTube(url)

my_video = my_video.streams.get_highest_resolution()

my_video.download()


