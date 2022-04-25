import { Dialog, Popover, Transition } from "@headlessui/react";
import { QuestionMarkCircleIcon, XIcon } from "@heroicons/react/outline";


interface Props {
    badWord: boolean;
    setBadWord:  React.Dispatch<React.SetStateAction<boolean>>;
}

export default function InvalidWordPopup({
    badWord,setBadWord
}: Props) {
  return (
    <Dialog
    open = {badWord}
    onClose={() => setBadWord(false)}
    >
          <Dialog.Title  className="fixed flex flex-col items-center justify-center gap-4 bg-gray-100 border border-gray-600 rounded-lg shadow-2xl top-20 left-4 right-4 md:w-3/12">
            <div className="flex justify-between w-full itemns-center">
              <h2 className="text-base font-semibold text-slate-700 md:text-lg lg:text-xl">
                Invalid word
              </h2>
            </div>
        </Dialog.Title>
    </Dialog>
  );
}
